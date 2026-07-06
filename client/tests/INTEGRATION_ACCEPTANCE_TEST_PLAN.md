# Client Integration & Acceptance Test Plan

이 파일은 Client QA가 Construction 단계에서 수행할 통합 및 인수 테스트 절차와 템플릿을 제공합니다.

## 준비 조건

- Server가 로컬 또는 테스트 환경에서 실행 중이어야 합니다 (예: `rtsp://localhost:8554/test`).
- Client가 빌드되어야 합니다.

```bash
cmake -S client -B client/build -DCMAKE_BUILD_TYPE=Debug
cmake --build client/build
```

## 통합 테스트 실행 (예)

```bash
# ctest 기반 통합 테스트
ctest --test-dir client/build -R integration --output-on-failure

# 또는 제공된 통합 테스트 스크립트
./client/scripts/run_integration_tests.sh --server-url rtsp://localhost:8554/test
```

## 인수 테스트(사용자 시나리오)

템플릿:

- Test ID: AT-1
- Title: Server 접속 및 스트림 재생
- Preconditions: Server 실행, 클라이언트 빌드 완료
- Steps:
  1. 클라이언트 실행
  2. Server 연결 정보 입력 및 연결 시도
  3. 스트림 재생 확인
- Expected Result:
  - 스트림이 재생된다.
  - 접속 상태 UI가 `connected`로 표시된다.
- Result: PASS / FAIL
- Notes: (스크린샷, 로그 파일 경로 등)

## 결과 기록 및 보고

- 모든 테스트 결과는 `client/tests/results/`에 저장합니다.
- 결과 요약은 Sprint 종료 보고에 포함시켜 `scrum-master`에게 제출합니다.

## 실패 처리

- 실패 시 재현 절차를 문서화하고, 관련 로그 및 네트워크 캡처를 첨부하여 GitHub 이슈를 생성합니다.
- Server 관련 문제로 확인되면 `area:server` 레이블로 이슈를 생성하고 `server-developer`를 Assignee로 지정합니다.
