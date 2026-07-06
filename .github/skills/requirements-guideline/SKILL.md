---
name: requirements-guideline
description: Requirements guideline for embedded SW systems, including business, management, and product requirement categories with quality attributes, compatibility, and interface expectations.
---

# Requirements-Guideline

Embedded SW 시스템에서 요구사항을 체계적으로 정리하기 위한 가이드입니다. 아래 항목은 첨부된 슬라이드의 구성에 맞춰 비즈니스 요구사항, 관리 요구사항, 제품 요구사항을 구분하고 품질 속성, 호환성, 인터페이스, UI/UX, 배포/운영 등 핵심 내용을 포함합니다.

## 1. 개요

- 제품과 시스템 요구사항을 명확히 분리합니다.
- 요구사항은 사용자의 관점과 시스템 품질 관점 모두를 반영해야 합니다.
- 라이선스 및 법적 제약을 조기에 파악하고 문서화합니다.

## 2. Business Requirements

- 사용 예정 라이브러리 및 구성 요소의 라이선스 검토 필요.
  - 예: FFmpeg, GStreamer 등
- 서비스 운영에 필요한 법적/규제 요구사항 확인.
- 고객 요구에 기반한 핵심 기능 정의.

## 3. Management Requirements

- 프로젝트 일정, 위험 관리, 품질 목표를 포함합니다.
- 품질 보증을 위한 테스트 전략과 검증 활동을 계획합니다.
- 개발/배포 환경, CI/CD 파이프라인, 운영 프로세스를 정의합니다.

## 4. Product Requirements

### 4.1 기능 요구 사항

- Use case / User story 형식으로 정리.
- 각 항목에 ID, 제목, 설명을 포함하여 사용자 요구 기준으로 작성.

### 4.2 품질 요구 사항 (ISO/IEC 25010-2023 기반)

- 자세한 품질 속성 설명은 `reference/ISO-IEC-25010-summary.md`를 참고하세요.
- Performance
  - 지연(latency) 목표
  - 허용 프레임 손실률
  - 최소/최대 비트레이트
  - CPU 및 메모리 예산
  - 가용성(SLA)
- Security
  - 인증 방식(토큰, OAuth, TLS 등)
  - 전송 암호화(TLS/SRTP)
  - 권한 모델(어드민 vs 일반 클라이언트)
  - 인증 만료 및 재인증 정책
- Reliability
  - 재연결 전략 및 백오프 규칙
  - 세션 타임아웃
  - 스트림 재생 실패 시 동작
  - 로그 및 알림 규칙
- Maintainability
  - 테스트 및 검증 범위
    - 성능 테스트(동시 연결, 스트리밍 품질)
    - 단위/통합 테스트 범위
    - 수동 검증 시나리오(화면 제어, 장애 주입)
- Portability
  - 배포/운영 환경
    - 이미지(베이스 OS)
    - 컨테이너 설정
    - CI/CD 파이프라인
    - 설정 파일 위치 및 환경 변수
    - 리소스 제한(쿠버네티스 등)
- Usability
  - 관리자 UI 기능
    - 로그 보기, 연결 관리, 알림, 녹화 관리
  - Client UI 기능
    - 사용자 관점의 제어 및 모니터링 기능

### 4.3 Compatibility

- 동시 연결 수(스케일) 요구사항
- 인터페이스 호환성
  - Client-Server Interface 프로토콜 및 포맷
    - RTSP 버전
    - 포트
    - 전송 방식(UDP/TCP/RTSP-over-HTTP)
    - 프로파일(Level/Baseline/Main/High)
    - 컨테이너(format)
  - 제어 명령 규격
    - 클라이언트 → 서버 제어 메시지 형식
      - 접속/해제, 프레임레이트, 해상도
      - 예: REST, WebSocket, RTCP, 커스텀 메시지
    - 페이로드 스키마(JSON 예시)
    - ACK/응답 타임아웃 및 오류 코드 정의

### 4.4 Camera Interface

- 지원할 카메라 인터페이스
  - ONVIF, RTSP native 등
- 최대 해상도 및 코덱 호환성
- 하드웨어 인코더 지원

### 4.5 UI Interface

- 로깅 및 모니터링
  - 로그 포맷, 수준(levels)
  - 모니터링 메트릭(비트레이트, 지연, 프레임 드랍)
  - 알림 조건, 외부 모니터링 연동(예: Prometheus)

## 5. 문서화 권장 사항

- 요구사항 식별 및 추적을 위한 명명 규칙 사용.
- 품질 속성별 검증 기준과 수용 기준을 명확히 작성.
- 변경 관리 이력을 유지하고 이해관계자 검토를 기록.

## 6. 사용 시점

- 시스템 설계 초기 단계에서 제품 요구사항과 품질 요구사항을 함께 정의합니다.
- 개발 및 테스트 단계에서는 관리 요구사항과 검증 전략을 주기적으로 점검합니다.
- 운영 단계에서는 배포/운영, 보안, 호환성 조건을 지속적으로 검증합니다.
