# Construction: Agent Workflows & Handoff Guide

이 문서는 Construction 단계에서의 에이전트 워크플로우(클라이언트 직접 Handoff, 서버 GitHub 이슈 기반 지시)를 정리합니다.

## 개요

- Client 개발 관련 작업은 `scrum-master`가 `client-developer` 에이전트에게 직접 Handoff 합니다.
- Server 개발 관련 작업은 `scrum-master`가 GitHub 이슈로 생성하여 `server-developer`에게 할당합니다.

## Scrum Master → Client 개발자 (직접 Handoff)

절차:

1. Sprint 계획 수립 중 `scrum-master`는 `client/docs/product-backlog.md` 내 항목을 검토 및 갱신합니다.
2. Handoff 항목을 선택하여 다음 정보를 준비합니다:
   - 작업 ID, 제목
   - 작업 설명 및 목표
   - Acceptance Criteria (측정 가능한 항목)
   - 우선순위 및 목표 스프린트
   - 관련 문서 링크
3. `scrum-master`는 `client-developer` 에이전트에게 `implement-task.prompt.md` 형식으로 직접 전달합니다.
4. `client-developer`는 24시간 이내에 수락/질문을 응답하고, 수락 시 작업 브랜치 생성 및 작업 착수합니다.
5. 구현 후 PR을 통해 Reviewer/QA에게 검토를 요청하고, 스프린트 종료 보고 시 `scrum-master`에게 결과를 보고합니다.

직접 Handoff 예시(프롬프트 내용):

```
Title: CL-4 RTSP 스트림 수신 및 표시
Description: Server의 RTSP/H.264 스트림을 수신하고 QT UI에 표시합니다.
Acceptance Criteria:
  1. 스트림이 플레이된다.
  2. 재생 실패 시 사용자에게 오류 표시.
Priority: high
Related: client/docs/product-backlog.md
```

## Scrum Master → Server Developer (GitHub Issue 기반)

절차:

1. `scrum-master`는 `server/docs/product-backlog.md`에서 작업을 선택합니다.
2. GitHub 이슈를 생성하고 아래를 포함합니다:
   - 작업 ID, 설명, Acceptance Criteria
   - 레이블: `area:server`, `type:...`, `priority:...`
   - Assignee 지정
3. `server-developer`는 이슈를 확인하고 24시간 내에 코멘트로 수락/이견/질문을 남깁니다.
4. 작업 착수 시 브랜치를 생성(`server/<issue-id>-<short>`)하고 개발을 진행합니다.
5. PR 생성 시 Windows 검증·로그를 첨부(필요 시)하고 Reviewer/QA 태그를 추가합니다.

GitHub 이슈 템플릿(본문 예시):

```
작업 ID: SR-3
제목: Frame Rate 제어 수신 및 검증
설명: Client로부터 전송된 Frame Rate 제어 명령을 수신하고, 유효성 검사 후 적용/응답
Acceptance Criteria:
  - 명령을 수신한다
  - 유효하지 않은 값은 오류 응답
관련 문서: server/docs/product-backlog.md
```

명령줄 예시(gh CLI):

```bash
gh issue create --title "SR-3: Frame Rate 제어 수신 및 검증" \
  --body "작업 ID: SR-3\n설명: ...\nAcceptance Criteria: ...\n관련 문서: server/docs/product-backlog.md" \
  --label "area:server" --label "type:feature" --label "priority:medium" --assignee "@server-developer"
```

## Reporting & 승인

- Sprint 시작 전: `scrum-master`는 지난 스프린트 결과를 요약 보고하고, 필요한 백로그 수정을 수행합니다.
- Sprint 중/종료: 각 에이전트는 상태를 `scrum-master`에게 보고합니다. Server 작업은 GitHub 이슈/PR로 추적되고, Client 작업은 백로그 항목/PR로 추적됩니다.

## 요약 규약 (슬라이드 기준 통합)

- Agent Allocation:
  - Client: Product Owner, Scrum Master, Architect, Client Developer, Product QA
  - Server: Server Developer
- Agent Workflow & Synchronization:
  - Client 내부 통신: Handoff
  - Client↔Server 통신: GitHub Issue

모든 Handoff는 24시간 내에 백로그 또는 이슈로 기록되며, 서버 영향 사항은 반드시 GitHub Issue로 생성되어 추적됩니다.

## QA: 통합 및 인수 테스트 실행 시점

- Client QA는 다음 시점에 통합(Integration) 및 인수(Acceptance) 테스트를 실행합니다:
  1. Construction Sprint의 중간 검증(기능 통합 확인)
  2. Sprint 종료 전(인수 테스트 및 수용 기준 검증)
  3. 주요 릴리스 전(릴리스 검증)

- 테스트 결과 보고:
  - 통합 테스트 실패는 즉시 Server/Client 담당자에게 할당되고 이슈로 등록합니다.
  - 인수 테스트 결과 요약(테스트 케이스, Pass/Fail, 스크린샷, 로그)은 Sprint 보고 자료에 포함됩니다.


## 참고

- 요구사항 작성은 항상 `requirements-guideline` 스킬을 사용하여 형식과 품질 속성 연결을 검증하세요.
- 변경 시 관련 문서(`client/docs/requirements.md`, `server/docs/requirements.md`, `common/docs/interface_contract.md`)를 업데이트하세요.
