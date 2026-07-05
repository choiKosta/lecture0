# Contributing

## Repository Checkout (Symlinks)

이 repository는 AI 코딩 에이전트 지침을 한 곳(`.github/copilot-instructions.md`, `.github/agents/`, `.github/skills/`)에만 두고, `AGENTS.md`, `CLAUDE.md`, `.claude/agents`, `.claude/skills`는 그 위치를 가리키는 **symlink**로 구성되어 있다. Linux/macOS/WSL에서는 별도 설정 없이 정상 동작한다.

**Windows에서 직접 `git clone`/checkout하는 경우**(Server 팀), 아래를 미리 설정하지 않으면 symlink가 대상 경로 문자열이 담긴 일반 텍스트 파일로 체크아웃되어 Copilot/Claude 등 에이전트 지침이 깨질 수 있다.

1. Windows 설정에서 "개발자 모드(Developer Mode)"를 켠다 (관리자 권한 없이 symlink 생성을 허용).
2. symlink 지원을 켠 상태로 clone한다.

   ```powershell
   git config --global core.symlinks true
   git clone -c core.symlinks=true <repo-url>
   ```

3. 이미 symlink 미지원 상태로 checkout했다면 아래로 재작성한다.

   ```powershell
   git config core.symlinks true
   git checkout-index -a -f
   ```

Client/공통 도구 설정에는 영향이 없으며, Server 프로젝트(Java/Gradle) 빌드·실행 자체는 이 symlink들과 무관하다.

## Development Flow

1. Issue를 생성하거나 기존 Issue를 선택한다.
2. 작업 브랜치를 생성한다.
3. 변경 사항을 구현한다.
4. 빌드 및 테스트를 실행한다.
5. Pull Request를 생성한다.

## Project Boundaries

- `client/`: Client 팀 소유 영역
- `server/`: Server 팀 소유 영역
- `common/`: Client와 Server 공동 소유 영역
- `tests/integration/`: Client와 Server 통합 검증 영역

한 PR은 가능한 한 하나의 프로젝트 영역만 변경한다. 다른 프로젝트 영역을 함께 변경해야 하는 경우 PR 설명에 이유를 적고 해당 영역 owner의 리뷰를 받는다.

프로젝트별 개발 명령과 검증 절차는 각 프로젝트 문서에서 관리한다.

- Client: [client/README.md](client/README.md)
- Server: [server/README.md](server/README.md)
- Common: [common/README.md](common/README.md)

## Branch Names

- `client/<issue-number>-<short-name>`
- `server/<issue-number>-<short-name>`
- `common/<issue-number>-<short-name>`
- `integration/<issue-number>-<short-name>`
- `docs/<issue-number>-<short-name>`

## Verification

- Client 변경은 `client/README.md`의 검증 절차를 따른다.
- Server 변경은 `server/README.md`의 Windows 검증 절차를 따른다.
- Common 변경은 `common/docs/interface_contract.md`의 변경 규칙을 따른다.
- 통합 변경은 `tests/integration/README.md`에 정의된 기준을 따른다.

## Commit Message

권장 형식:

```text
<type>: <summary>
```

예시:

```text
feat: add client connection controls
docs: add initial requirements
ci: add cmake build workflow
```
