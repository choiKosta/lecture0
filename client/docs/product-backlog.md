# Client Product Backlog

Client 프로젝트의 제품 백로그는 기존 `client/docs/requirements.md`를 기반으로 작성되었습니다.

## Epic 1: Server 연결 및 상태 표시

- CL-1: Server 접속 정보 입력/선택
  - 사용자에게 Server URL, 포트, 인증 정보를 입력 또는 선택할 수 있는 UI를 제공한다.
  - Acceptance Criteria:
    1. Server 접속 정보를 설정할 수 있다.
    2. 저장된 접속 정보를 재사용할 수 있다.

- CL-2: Server 접속 기능
  - Server에 연결 요청을 전송하고 연결 성공/실패를 처리한다.
  - Acceptance Criteria:
    1. Server에 정상적으로 접속할 수 있다.
    2. 접속 실패 시 사용자에게 오류 메시지를 표시한다.

- CL-3: 접속 상태 UI 표시
  - 현재 Server 연결 상태를 UI에 명확하게 표시한다.
  - Acceptance Criteria:
    1. 연결 중, 연결됨, 연결 해제 상태를 구분하여 보여준다.
    2. 상태 변경 시 UI가 즉시 갱신된다.

## Epic 2: 비디오 스트리밍 표시

- CL-4: RTSP/H.264 스트림 수신 및 표시
  - Server로부터 전달되는 스트림을 수신하고 화면에 표시한다.
  - Acceptance Criteria:
    1. RTSP/H.264 스트림을 정상적으로 재생한다.
    2. 스트리밍 재생 실패 시 오류 메시지를 표시한다.

## Epic 3: 화면 제어 명령

- CL-5: Frame Rate 제어 명령 송출
  - 사용자가 프레임 속도를 선택하거나 입력하면 Server에 제어 명령을 전송한다.
  - Acceptance Criteria:
    1. Frame Rate 제어 명령을 Server로 전송할 수 있다.
    2. Server 응답을 받아 성공/실패를 처리한다.

- CL-6: Resolution 제어 명령 송출
  - 사용자가 해상도를 선택하거나 입력하면 Server에 해당 명령을 전송한다.
  - Acceptance Criteria:
    1. Resolution 제어 명령을 Server로 전송할 수 있다.
    2. Server 응답을 받아 성공/실패를 처리한다.

## Epic 4: 오류 표시 및 사용자 경험

- CL-7: 오류 구분 표시
  - 접속 실패, 스트리밍 실패, 제어 명령 실패를 각각 구분하여 사용자에게 표시한다.
  - Acceptance Criteria:
    1. 오류 유형별로 다른 메시지를 표시한다.
    2. 사용자가 문제 해결을 시도할 수 있도록 적절한 안내를 제공한다.

## Epic 5: 개발/빌드/검증 환경

- CL-8: CMake 기반 빌드 설정
  - `camera_client`를 CMake로 빌드할 수 있도록 설정한다.
  - Acceptance Criteria:
    1. `cmake -S client -B client/build`가 성공한다.
    2. `cmake --build client/build`가 성공한다.

- CL-9: 테스트 및 CI 검증
  - Google Test 기반 테스트를 작성하고 GitHub Actions와 연동한다.
  - Acceptance Criteria:
    1. `ctest --test-dir client/build`가 성공한다.
    2. Client 변경 시 CI 검증이 자동으로 실행된다.
