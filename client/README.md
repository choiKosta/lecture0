# Client Project

카메라 관제 Client 프로젝트 영역입니다. 이 README는 Client 영역에 어떤 문서와 코드가 있는지만 안내합니다. 기능, 개발환경, 빌드, 검증 기준의 구체 내용은 요구사항 문서에서 관리합니다.

## Directory Contents

- `src/`: Client 구현 코드
- `include/`: Client public/private header
- `tests/`: Client 단위 테스트
- `docs/`: Client 요구사항 및 설계 문서
- `CMakeLists.txt`: Client 빌드 진입점

## Prototype Structure

- `include/camera_client/ui/`, `src/ui/`: 화면 흐름과 사용자 조작을 담당하는 UI 계층
- `include/camera_client/server_interface/`, `src/server_interface/`: 서버 접속, 스트림 정보, 제어 명령을 담당하는 서버 인터페이스 계층
- `camera_client_core`: UI 계층과 서버 인터페이스 계층을 묶는 Client 내부 라이브러리

현재 프로토타입은 실제 Server 구현에 연결하지 않고 `MockServerGateway`를 사용한다. UI 계층은 `IServerGateway` 인터페이스만 참조하므로, 추후 실제 RTSP/QT/OpenCV 연동 구현으로 교체할 수 있다.

## Documents

- [Client 요구사항](docs/requirements.md)

## Ownership

Client 팀이 소유합니다. Server 구현, Server 검증 절차, 공통 계약은 이 영역에서 관리하지 않습니다.
