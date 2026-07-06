# Camera Control Monorepo

카메라 관제 시스템의 Client, Server, 공통 계약 문서를 한 repository에서 관리한다. 각 프로젝트는 서로 다른 개발 환경을 사용하므로 루트 문서는 전체 구조와 ownership만 설명하고, 상세 개발/검증 방법은 각 프로젝트 문서에서 관리한다.

## Repository Layout

```text
.
├── client/              # Client 프로젝트
├── server/              # Server 프로젝트
├── common/              # Client-Server 공통 계약
├── tests/
│   └── integration/     # Client-Server 통합 테스트
├── docs/
│   ├── architecture/    # 아키텍처 문서
│   ├── project/         # 프로젝트 관리 문서
│   └── requirements/    # 요구사항 문서
└── .github/             # GitHub Issue, PR, CI 설정
```

## Project Ownership

- [client](client/README.md): Client 팀 소유 영역
- [server](server/README.md): Server 팀 소유 영역
- [common](common/README.md): Client 팀과 Server 팀 공동 소유. 인터페이스 계약과 공통 요구사항만 관리한다.
- [tests/integration](tests/integration/README.md): Client-Server 통합 검증 기준을 관리한다.

루트에는 프로젝트별 구현 세부사항을 두지 않는다. Client 상세는 `client/`, Server 상세는 `server/`, 양쪽 합의 사항은 `common/`에서 관리한다.

## Documents

-- System: [Requirements](docs/requirements/requirements.md), [아키텍처 개요](docs/architecture/overview.md), [프로젝트 관리](docs/project/project_management.md), [로드맵](docs/project/roadmap.md)
-- Client: [Client README](client/README.md), [Requirements](docs/requirements/requirements.md)
-- Server: [Server README](server/README.md), [Requirements](docs/requirements/requirements.md)
-- Common: [Common README](common/README.md), [Requirements](docs/requirements/requirements.md), [Interface Contract](common/docs/interface_contract.md)
