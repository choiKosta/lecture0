# Project Roadmap

본 문서는 repository 전체의 진행 항목을 프로젝트별로 분리해 관리한다. Client와 Server의 상세 일정은 각 프로젝트 owner가 관리하며, 양쪽에 영향을 주는 항목만 Common 또는 Integration에 둔다.

## Repository

- GitHub Issue/PR 템플릿 구성
- CODEOWNERS 기반 ownership 구성
- Client CI 구성
- Server Windows 검증 절차 문서화

## Client

- Client 프로젝트 구조 구성
- Client 빌드 및 테스트 절차 구성
- 기본 화면 구성
- 서버 접속 정보 입력 UI
- 접속 및 접속 해제 액션
- 상태 및 에러 메시지 표시
- 비디오 스트림 표시
- Frame Rate 및 Resolution 제어 요청 UI
- Client 실행 환경 검증

## Server

- Server 프로젝트 구조 구성
- Server Windows 개발 및 검증 절차 구성
- 스트림 송출 인터페이스 정의
- 테스트용 영상 소스 또는 카메라 입력 구성
- Client 제어 명령 수신 구조 구성
- 서버 상태 및 오류 응답 정의
- Server target runtime 검증

## Common

- RTSP URL 형식 정의
- 제어 명령 프로토콜 정의
- 제어 응답 프로토콜 정의
- Frame Rate 및 Resolution 지원 범위 정의
- 에러 코드 및 상태 코드 정의
- 버전 호환성 정책 정의

## Integration

- Client-Server 접속 시나리오 검증
- RTSP/H.264 스트리밍 연동 검증
- Frame Rate 및 Resolution 제어 명령 연동 검증
- 오류 응답과 Client 표시 연동 검증

## Completed Foundation

- Monorepo 구조 구성
- Client CMake 빌드 구성
- Server Gradle 빌드 구성
- GitHub Issue/PR 템플릿 구성
- Client CI 기본 빌드 및 테스트 구성
- Server Windows 검증 절차 문서화
