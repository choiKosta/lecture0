---
name: client-vscode-gdb-debug
description: Client-only (client/). VS Code Run and Debug (F5) setup and repair for the C++ camera_client in this WSL2 workspace — launch.json, tasks.json, and the gdb debuginfod wrapper. Use when F5 debugging breaks, breakpoints stop binding, the debug session hangs as "running", or run/debug configs need to be recreated or extended to a new gdb target.
---

# VS Code Run & Debug 설정 (camera_client, WSL2 + GDB)

2026-07-06에 검증 완료된 Run and Debug(F5) 구성과, 이 구성이 이렇게 되어 있어야만
하는 환경 제약을 기록한 문서입니다.

## 핵심 환경 제약 (필독)

이 WSL2 환경에서는 debuginfod.ubuntu.com으로의 연결이 SYN-SENT 상태로 멈춥니다
(패킷이 조용히 버려져 즉시 실패하지 않음). 그리고 gdb 15.1은 `set debuginfod
enabled off`를 -iex, setupCommands, .gdbinit 어디에 넣어도 **vDSO("system-supplied
DSO")에 대해서는 debuginfod 조회를 시도**합니다. 이 다운로드가 막히면 gdb의 MI
이벤트 스트림이 통째로 얼어붙어, VS Code에는 세션이 계속 실행 중으로 보이고
브레이크포인트가 잡히지 않는 것처럼 보입니다(pause/restart/stop만 활성화).
실제로는 프로그램이 정지된 상태입니다.

유일하게 확실한 해결책은 **gdb 프로세스** 환경에서 `DEBUGINFOD_URLS`를 제거하는
것입니다 (launch.json의 `"environment"`는 디버기에만 적용됨). 그 역할을 하는 것이
`.vscode/gdb-wrapper.sh`입니다:

```sh
#!/bin/sh
unset DEBUGINFOD_URLS
exec /usr/bin/gdb "$@"
```

실행 권한(`chmod +x`)이 유지되어야 하고 `miDebuggerPath`로 참조되어야 합니다.
**`miDebuggerPath`를 절대 `/usr/bin/gdb`로 되돌리지 마세요.**

## 구성 파일

- `.vscode/gdb-wrapper.sh` — 위의 gdb 래퍼. 이 설정의 핵심.
- `.vscode/launch.json` — 구성 2개:
  - **"Debug camera_client"** (`cppdbg`): `program` = `${workspaceFolder}/client/build/camera_client`,
    `cwd` = `${workspaceFolder}/client`, `stopAtEntry: true`,
    `miDebuggerPath` = `${workspaceFolder}/.vscode/gdb-wrapper.sh`,
    `miDebuggerArgs` = `-iex "set auto-load safe-path ${workspaceFolder}/client:/usr/share/gdb/auto-load" -iex "set debuginfod enabled off"`,
    `preLaunchTask` = `Build camera_client`. setupCommands의 debuginfod off와
    pretty-printing은 이중 방어이며, 실제로 hang을 막는 것은 래퍼입니다.
  - **"Run camera_client (no debugger)"** (`node-terminal`) — 빌드 후
    `./build/camera_client`를 터미널에서 실행.
- `.vscode/tasks.json` — 태스크:
  - `Configure camera_client`: `cmake -S client -B client/build -DCMAKE_BUILD_TYPE=Debug`
  - `Build camera_client`: `cmake --build client/build --target camera_client`,
    `dependsOn: ["Configure camera_client"]` + **`"dependsOrder": "sequence"` 필수** —
    VS Code는 dependsOn을 기본적으로 병렬 실행하므로, 이 옵션이 없으면 configure와
    build가 경쟁해 빌드 실패나 오래된 바이너리가 생깁니다.
  - `Check GDB ptrace permission`: gdb 배치 스모크 체크 (break main → run → bt).
- `client/.gdbinit` — `set debuginfod enabled off / confirm off / pagination off`;
  miDebuggerArgs의 auto-load safe-path로 허용됨.

## 점검 / 복구 절차

1. 래퍼가 존재하고 실행 가능하며 launch.json이 래퍼를 가리키는지 확인.
2. `Build camera_client` 태스크에 `dependsOrder: sequence`가 있는지 확인.
3. 빌드: `cmake -S client -B client/build -DCMAKE_BUILD_TYPE=Debug && cmake --build client/build`
4. 헤드리스 gdb 체크 (수 초 내에 브레이크포인트에 걸려야 정상):
   `cd client && DEBUGINFOD_URLS= gdb -q -batch -ex "break main" -ex run -ex bt ./build/camera_client`
5. VS Code 세션이 다시 hang되면: `ss -tnp | grep gdb` — 91.189.92.252:443으로의
   `SYN-SENT` 소켓이 보이면 debuginfod hang 재발(래퍼가 우회됨)입니다.
   `pgrep -f build/camera_client` 후 `grep State /proc/<pid>/status`가
   `t (tracing stop)`이면 gdb는 프로그램을 정지시켰고 UI/MI 연결만 막힌 것입니다.

## 새 디버그 타깃 추가

"Debug camera_client" 블록을 복사해 `name`/`program`/`preLaunchTask`만 바꾸세요.
`miDebuggerPath`는 래퍼를 그대로 유지 — camera_client뿐 아니라 이 워크스페이스의
모든 gdb 타깃에 해당합니다. 터미널에서 직접 gdb를 쓸 때도
`DEBUGINFOD_URLS= gdb ...`로 실행해야 합니다.

대화형 입력(std::cin)이나 ncurses처럼 터미널을 직접 제어하는 프로그램을 디버깅할
때는 `"externalConsole": true`를 준 구성을 추가하면 별도 터미널 창으로 입출력이
분리됩니다.
