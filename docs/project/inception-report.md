# Inception 결과 보고서

이 문서는 현재까지 진행된 Inception 단계의 결과를 요약하고, 이후 Construction Sprint로 전환하기 위한 준비 사항을 정리합니다.

## 1. 프로젝트 구조 개요

### 1.1 디렉터리 구조

- `client/`
  - C++ 기반 QT/OpenCV 클라이언트
  - 빌드 및 테스트: CMake, Google Test
  - Client 요구사항 및 백로그 문서 포함
- `server/`
  - Java Spring Boot 서버 + RTSP/H.264 스트리밍 인터페이스
  - 빌드 및 배포: Gradle, Docker
  - Server 요구사항 및 백로그 문서 포함
- `common/`
  - Client-Server 공통 인터페이스 계약 및 요구사항
- `tests/integration/`
  - Client와 Server 통합 검증 시나리오
- `docs/`
  - 아키텍처, 프로젝트 관리, 요구사항 문서
- `.github/`
  - 에이전트/프롬프트/스킬 정의
  - CI 및 운영 관련 파일

### 1.2 에이전트 및 워크플로우 구조

- 역할 기반 에이전트
  - `product-owner` – 요구사항 및 Acceptance Criteria 정의
  - `scrum-master` – 스프린트 계획, 백로그 관리, 진행 보고
  - `architect` – 시스템 아키텍처 및 인터페이스 설계
  - `client-developer` – C++ 클라이언트 구현
  - `server-developer` – 서버 구현 및 REST/RTSP 연동
  - `ai-developer` – 얼굴 인식/ONNX/TensorRT 관련 AI 통합
  - `reviewer` – 코드/설계/품질 검토
  - `qa` – 테스트 케이스, 회귀, Definition of Done 검증
- 에이전트 오케스트레이션
  - `agent-orchestration`이 Product Owner → Scrum Master → Architect → Developer → Reviewer → QA 흐름을 관리

### 1.3 프롬프트 및 스킬

- 프롬프트
  - user story 작성: `create-user-story.prompt.md`
  - 스프린트 계획: `plan-sprint.prompt.md`
  - 구현 작업: `implement-task.prompt.md`
  - 검토: `review-code.prompt.md`, `review-requirements.prompt.md`
  - 테스트 케이스 작성: `create-test-cases.prompt.md`
  - 회고: `create-retrospective.prompt.md`
  - 스프린트 결과 보고: `review-sprint-results.prompt.md`
- 스킬
  - `requirements-guideline`: 요구사항 작성/검증 지침
  - `client-vscode-gdb-debug`: Client 디버그 환경 복구 및 설정
  - `project-setup-info-local`: 로컬 프로젝트 환경 구성 안내
  - 역할별 스킬 정의: Client/Server/AI/Architect/QA 등

## 2. 요구사항 및 백로그


### 2.1 Client 요구사항

- `docs/requirements/requirements.md`에 Client 책임 범위와 기능 요구사항 정의
- 핵심 기능
  - Server 접속 및 접속 상태 표시
  - RTSP/H.264 스트림 수신 및 화면 표시
  - Frame Rate/Resolution 제어 명령 송출
  - 오류 구분 및 사용자 안내
- 환경 요구사항
  - Ubuntu/WSL2, VS Code, g++, CMake, Qt, OpenCV, Google Test


### 2.2 Server 요구사항

- `docs/requirements/requirements.md`에 Server 책임 범위와 기능 요구사항 정의
- 핵심 기능
  - RTSP/H.264 스트림 제공
  - Client 접속 요청 처리
  - 제어 명령 수신 및 검증
  - 오류 상태 및 응답 제공
- 환경 요구사항
  - Ubuntu/Windows, IntelliJ, Gradle, Docker, Java

### 2.3 분리된 Product Backlogs

- `docs/requirements/productbacklogs/client-product-backlog.md`
  - Client 연결/스트리밍/화면 제어/오류 표시/빌드 및 CI 백로그
- `docs/requirements/productbacklogs/server-product-backlog.md`
  - RTSP 스트리밍, 연결 관리, 제어 명령 처리, 오류 상태, 운영 환경 백로그

## 3. 시스템 아키텍처 요약

- Client와 Server는 분리된 프로젝트로 병렬 개발
- Client는 QT 기반 UI에서 Server RTSP 스트림 수신 및 제어 요청 전송
- Server는 RTSP/H.264 스트림을 제공하고 제어 명령을 수신하여 검증 및 응답
- 공통 인터페이스 계약은 `common/`에 문서화하여 Client/Server 간 호환성 관리

## 4. 개발 환경 및 설정

### 4.1 Client 개발 환경

- OS: Ubuntu 또는 WSL2
- IDE: VS Code
- 빌드: CMake
- 컴파일러: g++
- 디버깅: gdb
- 라이브러리: Qt, OpenCV
- 테스트: Google Test
- CI: GitHub Actions (Client CMake 검증 자동화)

### 4.2 Server 개발 환경

- Target Runtime OS: Ubuntu
- 개발 OS: Windows
- IDE: IntelliJ IDEA
- 빌드/배포: Gradle, Docker
- 언어: Java
- 검증: Windows 환경에서 Gradle 빌드/테스트

### 4.3 에이전트/도구 구성

- `.github/agents/`에 역할별 agent 정의
- `.github/prompts/`에 역할별 프롬프트 정의
- `.github/skills/`에 요구사항 및 디버그/환경 설정 스킬 정의
- `requirements-guideline` 스킬로 요구사항 작성과 검증 표준화

## 5. 일정 및 다음 단계

### 5.1 Inception 종료 기준 달성

- 프로젝트 소유권과 책임 분리: Client/Server 별 독립 백로그 및 요구사항 정리
- 아키텍처 방향 수립: Client-Server 분리, RTSP/제어 명령 인터페이스 정의
- 개발 환경 정의: Client/Server 각기 다른 개발/검증 요구사항 확정
- 에이전트 기반 개발 프로세스 정립: 역할별 에이전트, 프롬프트, 스킬 구성

### 5.2 Construction Sprint 진입 준비

- 첫 Construction Sprint 목표
  - Client: Server 접속/스트리밍 수신 및 UI 상태 표시 기능 구현
  - Server: RTSP 스트리밍 제공 및 Client 접속 처리 구현
- Sprint 계획
  - 스프린트 별 스코프를 Client/Server로 분리하여 관리
  - 스프린트 시작 전 지난 스프린트 결과 보고 및 백로그 재검토
  - 스프린트 종료 후 회고 및 백로그 수정
- 검증 기준
  - Client: `cmake -S client -B client/build && cmake --build client/build && ctest --test-dir client/build`
  - Server: `cd server && gradle build && gradle run`

## 6. 결론

현재까지 Inception 단계에서는 프로젝트 범위를 분리하고, 역할 기반 에이전트 및 문서 구조를 구성했으며, Client/Server 각각의 백로그와 개발 환경을 확정했습니다. 이후 Construction Sprint에서는 각 백로그의 항목을 실제 구현으로 전환하고, 스프린트 루프를 통해 지속적으로 백로그를 갱신하며 진화시켜야 합니다.
