# 시스템 아키텍처 개요

## 시스템 구성

카메라 관제 시스템은 Client-Server 구조로 구성한다.

- Client: 사용자 UI, 서버 접속/해제, 화면 제어 명령 송출, 비디오 스트림 표시
- Server: RTSP/H.264 스트림 제공, Client 제어 명령 처리
- Common: Client와 Server가 공유하는 인터페이스 계약과 공통 문서

## Repository Boundary

```text
client
  Client implementation
  Client requirements
  Client build and verification guide

server
  Server implementation
  Server requirements
  Server build and verification guide

common
  interface contract
  shared requirements
  error/status code documents
```

## 구현 원칙

- 프로젝트별 구현 기술과 빌드 도구는 각 프로젝트 내부 문서에서만 설명한다.
- 인터페이스 계약과 공통 요구사항은 `common`에 둔다.
- Client 전용 문서는 `client/docs`에 둔다.
- Server 전용 문서는 `server/docs`에 둔다.
- 양쪽에 영향을 주는 변경은 `common/docs/interface_contract.md`를 먼저 갱신한다.
- 루트 문서는 전체 구조, ownership, 운영 정책만 설명한다.
