# Sprint 1 — Server 실행 및 검증 보고서 (SR-1)

- 작업 ID: SR-1
- 관련 이슈: #1
- 브랜치: `server-sprint1`
- 검증 일자: 2026-07-06
- 검증 환경: Windows 11 (개발/검증 OS), IntelliJ IDEA

## 검증 환경 상세

| 항목 | 값 |
|---|---|
| OS | Windows 11 Home (10.0.26200) |
| JDK | Microsoft Build of OpenJDK 17.0.19 (`C:\Program Files\Microsoft\jdk-17.0.19.10-hotspot`) |
| Build Tool | Gradle 9.3.0 (Gradle Wrapper) |
| Build Target | Gradle application `camera-server` |
| Main Class | `com.example.camera.server.CameraServerApplication` |

## Acceptance Criteria 결과

| # | 기준 | 결과 | 비고 |
|---|---|---|---|
| 1 | Server 빌드 성공 (`./gradlew build`) | ✅ 통과 | `BUILD SUCCESSFUL in 14s` |
| 2 | 통합(Integration) 테스트 통과 | ⚠️ 해당 없음 | 자동 테스트 미존재 (`test` = NO-SOURCE). 아래 "미해결 사항" 참고 |
| 3 | 결과 보고서 업데이트 | ✅ 완료 | 본 문서 (`server/sprints/sprint-1-report.md`) |
| 4 | 실패 시 후속 이슈 생성 (`area:server`) | — | 빌드/실행 실패 없음. 테스트 부재는 후속 과제로 별도 기록 |

## 실행 로그

### `gradlew --version`
```
Gradle 9.3.0
Daemon JVM: C:\Program Files\Microsoft\jdk-17.0.19.10-hotspot (Java 17)
```

### `gradlew clean build --no-daemon`
```
> Task :clean
> Task :compileJava
> Task :processResources NO-SOURCE
> Task :classes
> Task :jar
> Task :startScripts
> Task :distTar
> Task :distZip
> Task :assemble
> Task :compileTestJava NO-SOURCE
> Task :processTestResources NO-SOURCE
> Task :testClasses UP-TO-DATE
> Task :test NO-SOURCE
> Task :check UP-TO-DATE
> Task :build

BUILD SUCCESSFUL in 14s
6 actionable tasks: 6 executed
```

### `gradlew run --no-daemon`
```
Camera Server scaffold
```

## 요약

- Windows 개발 환경에서 `camera-server`의 **빌드(`build`)와 실행(`run`)이 모두 성공**함을 확인.
- 현재 서버는 스캐폴드 단계로, `main`이 `Camera Server scaffold`를 출력하고 정상 종료함.
- 이로써 운영 백로그 SR-7(빌드/실행 성공), SR-8(Windows 검증 기록)의 검증 근거를 확보함.

## 미해결 사항 / 후속 과제

1. **자동 테스트 부재**: `server/src/test/java`가 비어 있어 `test` 태스크가 NO-SOURCE로 처리됨. AC #2(통합 테스트)를 실질적으로 만족하려면 테스트 코드가 필요함.
2. **통합 테스트 영역 미정의**: `tests/integration/`은 시나리오가 아직 정의되지 않음(README만 존재).
3. 후속 조치 제안: `area:server`, `type:task` 라벨로 "Server 단위/통합 테스트 스캐폴드 추가" 이슈를 생성하여 다음 스프린트에서 다룸.
