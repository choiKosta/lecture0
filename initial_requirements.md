# 카메라 관제 시스템 요구사항 문서 인덱스

본 문서는 repository 루트에서 요구사항 문서의 위치를 안내하기 위한 인덱스이다. Client와 Server는 서로 다른 개발 환경과 책임 범위를 가지므로 상세 요구사항은 프로젝트별 문서에서 관리한다.

## 문서 분리 원칙

- Client 전용 요구사항은 `client/docs`에서 관리한다.
- Server 전용 요구사항은 `server/docs`에서 관리한다.
- Client와 Server가 함께 합의해야 하는 내용은 `common/docs`에서 관리한다.
- 통합 검증 기준은 `tests/integration`에서 관리한다.
- 루트 문서는 프로젝트별 상세 구현, 빌드, IDE 설정을 포함하지 않는다.

## 요구사항 문서

- [Client 요구사항](client/docs/requirements.md)
- [Server 요구사항](server/docs/requirements.md)
- [Common 요구사항](common/docs/requirements.md)
- [Client-Server Interface Contract](common/docs/interface_contract.md)
- [통합 테스트 기준](tests/integration/README.md)

## 시스템 요약

카메라 관제 시스템은 Client-Server 구조로 구성한다.

- Client는 사용자가 서버에 접속하고 비디오 스트림을 확인하며 화면 제어 명령을 요청하는 영역이다.
- Server는 영상 스트림을 제공하고 Client 제어 명령을 처리하는 영역이다.
- Common은 양쪽이 함께 지켜야 하는 프로토콜, 오류 코드, 지원 범위, 호환성 정책을 관리하는 영역이다.

## 원본 슬라이드 기반 초기 항목

초기 슬라이드에서 도출된 주요 항목은 아래 프로젝트별 문서로 분리해 반영한다.

- 서버 접속 및 접속 해제
- RTSP/H.264 비디오 스트리밍
- Frame Rate 및 Resolution 제어
- 오류 메시지 표시 및 오류 응답
- Client 개발 환경
- Server 개발 및 검증 환경
- Client-Server 인터페이스 계약
