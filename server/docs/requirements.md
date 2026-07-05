# Server 요구사항

## 책임 범위

Server는 카메라 또는 테스트 영상 소스를 기반으로 RTSP/H.264 스트림을 제공하고, Client가 송출한 제어 명령을 수신 및 처리한다.

## 기능 요구사항

- RTSP/H.264 기반 비디오 스트림을 제공해야 한다.
- Client 접속 요청을 처리해야 한다.
- Client 접속 해제 또는 연결 종료 상황을 처리해야 한다.
- Frame Rate 제어 명령을 수신하고 검증해야 한다.
- Resolution 제어 명령을 수신하고 검증해야 한다.
- 지원 가능한 Frame Rate 및 Resolution 범위를 제공해야 한다.
- 제어 명령 처리 결과를 Client가 확인할 수 있도록 응답해야 한다.
- 스트리밍 또는 제어 처리 중 오류가 발생하면 명확한 오류 상태를 제공해야 한다.

## 실행 환경

- Target Runtime OS: Ubuntu
- Server Interface: RTSP/H.264
- IDE: IntelliJ IDEA
- Package/Deployment Tool: Gradle, Docker
- Language: Java
- Build Tool: Gradle

## 개발 및 검증 환경

- OS: Windows
- IDE: IntelliJ IDEA
- Build/Verification Tool: Gradle
- Server 변경 사항은 Windows 환경에서 빌드 및 테스트한다.

## 빌드 및 검증 요구사항

- Build Target: Gradle application `camera-server`
- 서버 빌드와 테스트는 Windows 개발 환경에서 수행한다.
- 서버 변경 PR에는 Windows 환경에서 실행한 Gradle 명령과 결과를 기록한다.
- 기본 빌드 명령:

```bash
cd server
gradle build
```

- 기본 실행 명령:

```bash
cd server
gradle run
```

## 제외 범위

- Client UI 표시
- 사용자 입력 처리
- Client 화면 렌더링
- Client CMake 검증 절차
