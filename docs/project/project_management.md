# 프로젝트 관리 구조

## GitHub 운영 단위

- Milestone: Client, Server, Common/Contract, Integration 단위로 생성
- Issue: 기능, 버그, 작업, 문서 단위로 생성
- Pull Request: 하나의 명확한 변경 목적을 기준으로 생성
- GitHub Actions: repository 공통 자동화. 현재는 Client 검증만 자동 실행
- Client 검증: `client/README.md` 기준
- Server 검증: `server/README.md` 기준
- Common 변경 검증: `common/docs/interface_contract.md` 기준

## 권장 Label

- `type:feature`: 신규 기능
- `type:bug`: 결함 수정
- `type:task`: 개발 작업
- `type:docs`: 문서 작업
- `area:client`: Client 관련
- `area:server`: Server 관련
- `area:common`: 공통 계약 및 공통 문서 관련
- `area:integration`: Client-Server 통합 관련
- `area:infra`: GitHub Actions, repository 운영, 프로젝트별 빌드 설정 관련
- `priority:high`: 우선순위 높음
- `priority:medium`: 우선순위 보통
- `priority:low`: 우선순위 낮음

## Branch Strategy

- `main`: 안정 브랜치
- `client/<issue-number>-<short-name>`: Client 작업
- `server/<issue-number>-<short-name>`: Server 작업
- `common/<issue-number>-<short-name>`: 공통 계약 또는 공통 문서 작업
- `integration/<issue-number>-<short-name>`: 통합 작업
- `docs/<issue-number>-<short-name>`: 문서 변경

## Ownership

- `client/`: Client 팀 소유
- `server/`: Server 팀 소유
- `common/`: Client 팀과 Server 팀 공동 소유
- `tests/integration/`: Client 팀과 Server 팀 공동 소유
- `docs/project/`: 프로젝트 운영 담당자 소유

한 프로젝트의 PR이 다른 프로젝트 디렉터리를 변경할 수는 있지만, 해당 영역의 Code Owner 승인을 받아야 merge할 수 있다.

## Definition of Ready

- 요구사항 또는 문제 설명이 명확하다.
- 완료 기준이 작성되어 있다.
- 관련 영역과 우선순위가 지정되어 있다.
- 필요한 경우 테스트 방법이 포함되어 있다.

## Definition of Done

- 코드 또는 문서 변경이 요구사항을 충족한다.
- 변경 영역에 해당하는 프로젝트 문서의 검증 절차를 완료했다.
- PR 설명에 변경 사항과 검증 결과가 포함되어 있다.
- 신규 동작이 있으면 문서가 갱신되어 있다.
- 다른 프로젝트 영역을 변경한 경우 해당 프로젝트 owner의 리뷰를 받았다.
