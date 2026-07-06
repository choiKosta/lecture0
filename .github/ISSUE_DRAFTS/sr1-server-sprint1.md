---
title: "SR-1: Sprint 1 — Server 실행 및 검증 (Draft)"
labels: ["area:server", "type:task", "priority:high"]
assignees: ["server-developer"]
generated: 2026-07-06T00:00:00Z
---

# SR-1: Sprint 1 — Server 실행 및 검증 (Draft)

- 작업 ID: SR-1
- 요약: Sprint 1 기간 동안 Server 측 빌드, 통합 테스트 및 검증을 수행합니다.
- 목적: Server가 Sprint 1 목표(스트리밍, 연결 처리 등)를 만족하는지 확인하고 결과를 `server/sprints/sprint-1-report.md`에 기록합니다.

## Acceptance Criteria
1. Server 빌드 성공 (`./gradlew build` 또는 `gradle build`)
2. 통합(Integration) 테스트 통과
3. 결과 보고서 `server/sprints/sprint-1-report.md` 업로드 또는 업데이트
4. 실패 시 관련 이슈(버그/환경)를 생성하고 `area:server` 레이블을 붙임

## 작업 항목 (Steps)
- [ ] 브랜치 생성: `server/SR-1-sprint1`
- [ ] 서버 빌드 및 의존성 확인 (`./gradlew build`)
- [ ] 통합 테스트 실행 및 결과 수집
- [ ] 로그/스크린샷 첨부 및 `server/sprints/sprint-1-report.md` 업데이트
- [ ] PR 생성 및 Reviewer/QA 태그

## 관련 문서
- `docs/project/sprint-1-plan.md`
- `docs/requirements/product-backlog.md` (canonical 확인 필요)
- `server/sprints/sprint-1-backlog.md`

## 예시 `gh` 명령 (로컬에서 실행)
```bash
gh issue create --title "SR-1: Sprint 1 — Server 실행 및 검증" \
  --body-file ".github/ISSUE_DRAFTS/sr1-server-sprint1.md" \
  --label "area:server" --label "type:task" --label "priority:high" \
  --assignee "@server-developer"
```

---
Note: This is a draft. Review and edit the body before running the above `gh` command to create the actual issue.
