# Copilot Instructions

이 repository는 Camera Control Monorepo이다. Copilot은 아래 규칙을 우선 적용해 코드, 문서, template 변경을 제안해야 한다.

## Repository Boundary

최상위 영역은 다음 책임으로 분리한다.

- `client/`: Client 프로젝트
- `server/`: Server 프로젝트
- `common/`: Client-Server 공통 계약
- `tests/integration/`: Client-Server 통합 검증 기준
- `docs/`: 시스템, 프로젝트 운영, 요구사항 문서
- `.github/`: GitHub Issue, PR, CI 설정

루트 문서는 전체 구조와 ownership만 설명한다. 루트 README에 Client 또는 Server의 상세 빌드 명령, IDE 설정, 구현 세부사항을 추가하지 않는다.

## Project Separation

- Client 전용 요구사항, 개발환경, 빌드, 검증 절차는 `client/` 아래에서만 관리한다.
- Server 전용 요구사항, 개발환경, 빌드, 검증 절차는 `server/` 아래에서만 관리한다.
- 프로젝트 README는 해당 디렉터리에 무엇이 있는지만 안내한다.
- 기능, 개발환경, 빌드, 검증 기준의 구체 내용은 각 프로젝트의 `docs/requirements.md`에 둔다.
- Client와 Server가 함께 지켜야 하는 프로토콜, 오류 코드, 지원 범위, 호환성 정책은 `common/` 아래에서만 관리한다.
- 통합 검증 시나리오는 `tests/integration/` 아래에서 관리한다.
- Server 관련 상세 내용을 Client 문서에 추가하지 않는다.
- Client 관련 상세 내용을 Server 문서에 추가하지 않는다.
- 공통 계약 변경은 구현 변경보다 먼저 `common/docs/interface_contract.md`에 문서화한다.

## Ownership

- `client/`: Client 팀 소유
- `server/`: Server 팀 소유
- `common/`: Client 팀과 Server 팀 공동 소유
- `tests/integration/`: Client 팀과 Server 팀 공동 소유
- `docs/`: 문서 owner 또는 관련 영역 owner 소유
- `.github/`: repository 운영 owner 소유

한 PR은 가능한 한 하나의 ownership 영역만 변경한다. 다른 영역을 함께 변경해야 하는 경우 PR에 이유와 영향 범위를 기록하도록 안내한다.

## Build and Verification

- Client 변경은 `client/README.md`의 검증 절차를 따른다.
- Server 변경은 `server/README.md`의 Windows 검증 절차를 따른다.
- Common 변경은 `common/docs/interface_contract.md`의 변경 규칙을 따른다.
- Integration 변경은 `tests/integration/README.md` 기준으로 검증한다.
- 현재 GitHub Actions 자동 CI는 Client 검증만 수행한다.
- Server 변경 PR에는 별도 Windows 개발 환경에서 수행한 검증 결과를 기록해야 한다.

## GitHub Files

GitHub가 자동 인식해야 하는 파일은 `.github/` 아래에 둔다.

- Issue templates: `.github/ISSUE_TEMPLATE/`
- Pull request template: `.github/pull_request_template.md`
- GitHub Actions workflows: `.github/workflows/`
- Copilot repository instructions: `.github/copilot-instructions.md`

Issue template은 기능 요청, 버그, 작업을 구분한다. PR template은 변경 영역, cross-project 영향, 검증 결과를 기록하도록 유지한다.

## Branch Naming

작업 브랜치는 변경 영역을 드러내는 prefix를 사용한다.

```text
client/<issue-number>-<short-name>
server/<issue-number>-<short-name>
common/<issue-number>-<short-name>
integration/<issue-number>-<short-name>
docs/<issue-number>-<short-name>
```

## Pull Request Guidance

PR 설명에는 다음 항목이 포함되어야 한다.

- 변경 요약
- 변경 영역
- 다른 프로젝트 영역에 미치는 영향
- 수행한 검증 결과
- 관련 Issue

Common 계약을 변경하는 PR은 Client owner와 Server owner의 리뷰가 모두 필요하다.

## Repository-Wide Change Control

다음 변경은 repository 전체에 영향을 줄 수 있으므로 영향 범위와 관련 owner 리뷰를 요구한다.

- 최상위 디렉터리 구조 변경
- ownership 변경
- `.github/` template 또는 workflow 변경
- `CODEOWNERS` 변경
- `common/docs/interface_contract.md` 변경
- branch naming 또는 PR 검증 정책 변경
