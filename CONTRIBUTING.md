# Contributing

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
