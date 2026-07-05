# Client-Server Interface Contract

## 목적

본 문서는 Client와 Server가 함께 지켜야 하는 인터페이스 계약을 관리한다. Client 또는 Server 중 한쪽만의 구현 세부 사항은 각 프로젝트 문서에서 관리한다.

## 초기 계약 항목

### Streaming

- Protocol: RTSP
- Encoding: H.264
- RTSP URL 형식은 추후 확정한다.

### Control Commands

- 접속
- 접속 해제
- Frame Rate 변경
- Resolution 변경

### Control Responses

- 성공
- 요청 형식 오류
- 지원하지 않는 값
- 서버 내부 오류
- 스트림 상태 오류

### Error Model

- Client 표시용 메시지와 Server 내부 로그 메시지는 분리한다.
- 공통 오류 코드는 `common`에서 관리한다.
- 상세 메시지와 복구 방법은 각 프로젝트 문서에서 관리한다.

## 변경 규칙

- 본 계약을 변경하는 PR은 Client owner와 Server owner의 리뷰를 모두 받아야 한다.
- 계약 변경 시 관련 요구사항, 테스트, 릴리스 노트를 함께 갱신한다.

