# Client 요구사항

## 책임 범위

Client는 사용자가 서버에 접속하고, 서버가 제공하는 영상을 확인하며, 화면 제어 명령을 송출할 수 있는 QT 기반 UI 애플리케이션이다.

## 1. 기능 요구사항

### 1.1 서버 접속

- Server 접속 정보를 입력하거나 선택할 수 있어야 한다.
- Server에 접속할 수 있어야 한다.
- Server와의 접속을 해제할 수 있어야 한다.
- 접속 상태를 UI에 표시해야 한다.

### 1.2 비디오 스트리밍

- Server로부터 송출되는 RTSP/H.264 비디오 스트림을 표시해야 한다.

### 1.3 화면 제어

- Frame Rate 제어 명령을 Server에 송출할 수 있어야 한다.
- Resolution 제어 명령을 Server에 송출할 수 있어야 한다.

### 1.4 오류 표시

- 접속 실패, 스트리밍 실패, 제어 명령 실패를 구분하여 표시해야 한다.

## 2. 환경 요구사항

### 2.1 개발 환경

- OS: Ubuntu 또는 WSL2
- IDE: VS Code
- VS Code
  - Extensions
    - C/C++
    - CMake Tools
    - C++ TestMate 또는 Google Test Adapter
    - Docker
  - Run and Debug 툴바 버튼 활성화
- Language: C++
- Compiler: g++
- Debugging Tool: gdb
- Libraries:
  - QT
  - OpenCV

### 2.2 빌드 및 배포 환경

- Build Target: `camera_client`
- Build Tool: CMake
- Package Tool: vcpkg
- Deployment Tool: Docker

### 2.3 테스트 및 CI/CD 환경

- Test Tool: Google Test
- CI/CD Tool: GitHub Actions
- Client 변경은 Linux 또는 WSL2 환경에서 CMake configure, build, test 절차를 통과해야 한다.
- GitHub Actions는 Client CMake 검증을 자동 수행해야 한다.
- 기본 검증 명령:

```bash
cmake -S client -B client/build
cmake --build client/build
ctest --test-dir client/build
```

## 3. 제외 범위

- RTSP/H.264 스트림 생성
- 카메라 장치 직접 제어
- 서버 내부 상태 관리
- 제어 명령의 최종 적용 로직
- Server 구현 또는 Server Windows 검증 절차
