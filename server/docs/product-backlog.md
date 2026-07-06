# Server Product Backlog

Server 프로젝트의 제품 백로그는 기존 `server/docs/requirements.md`를 기반으로 작성되었습니다.

## Epic 1: RTSP 스트리밍 제공

- SR-1: RTSP/H.264 비디오 스트림 제공
  - 카메라 또는 테스트 영상 소스로부터 RTSP 스트림을 생성하여 제공한다.
  - Acceptance Criteria:
    1. RTSP/H.264 스트림을 정상적으로 제공한다.
    2. 클라이언트가 스트림을 수신할 수 있다.

## Epic 2: 클라이언트 연결 관리

- SR-2: Client 접속 요청 처리
  - Client의 접속 요청을 수신하고 연결 상태를 관리한다.
  - Acceptance Criteria:
    1. 접속 요청을 정상적으로 처리한다.
    2. 접속 해제 또는 연결 종료를 처리한다.

## Epic 3: 제어 명령 처리

- SR-3: Frame Rate 제어 명령 수신 및 검증
  - Client가 보낸 Frame Rate 명령을 수신하고 유효성을 검사한다.
  - Acceptance Criteria:
    1. 명령을 수신할 수 있다.
    2. 지원 범위를 벗어난 값은 적절히 오류 처리한다.

- SR-4: Resolution 제어 명령 수신 및 검증
  - Client가 보낸 Resolution 명령을 수신하고 유효성을 검사한다.
  - Acceptance Criteria:
    1. 명령을 수신할 수 있다.
    2. 지원 범위를 벗어난 값은 적절히 오류 처리한다.

- SR-5: 제어 명령 결과 응답
  - 제어 명령 처리 결과를 Client에 응답한다.
  - Acceptance Criteria:
    1. 성공/실패 결과를 응답한다.
    2. 명확한 상태 메시지를 포함한다.

## Epic 4: 오류 상태 관리

- SR-6: 스트리밍 또는 제어 처리 오류 상태 제공
  - 오류 발생 시 명확한 오류 상태를 유지하고 Client에 전달한다.
  - Acceptance Criteria:
    1. 오류 발생 시 상태를 기록한다.
    2. Client가 오류 내용을 확인할 수 있다.

## Epic 5: 서버 운영 환경

- SR-7: Ubuntu 및 Gradle 실행 환경
  - 서버를 Ubuntu 환경에서 Gradle로 빌드 및 실행할 수 있도록 설정한다.
  - Acceptance Criteria:
    1. `cd server && gradle build`가 성공한다.
    2. `cd server && gradle run`이 성공한다.

- SR-8: Windows 개발 환경 검증 기록
  - Server 변경 PR에 Windows 실행 결과를 기록한다.
  - Acceptance Criteria:
    1. Windows 환경에서 Gradle 빌드/테스트 결과를 문서화한다.
