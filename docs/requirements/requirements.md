# System Requirements (Unified)

This document consolidates Client, Server, and Common requirements into a single canonical requirements document stored under `docs/requirements/requirements.md`.

## Purpose

Provide a single source-of-truth for system requirements, scope, environment, and cross-cutting contracts. This file replaces per-project `client/docs/requirements.md`, `server/docs/requirements.md`, and `common/docs/requirements.md`.

## Contents
- Responsibilities and scope (Client, Server, Common)
- Functional requirements (Client & Server)
- Environment and build requirements
- Interface contract reference and integration items
- Exclusions

---

# Client Requirements

## Responsibility

Client is a Qt-based UI application that allows users to connect to the Server, view RTSP/H.264 streams, and send screen control commands.

## Functional Requirements

- Server connection input/selection UI (Server URL, port, auth)
- Server connect/disconnect handling
- Connection state UI (connecting/connected/disconnected)
- RTSP/H.264 video stream playback in UI
- Frame Rate control command (send to Server)
- Resolution control command (send to Server)
- Distinct error reporting and actionable guidance

## Environment & Build

- OS: Ubuntu or WSL2
- Language: C++ (g++)
- Build: CMake (`cmake -S client -B client/build` and `cmake --build client/build`)
- Debug: gdb, VS Code recommended extensions (C/C++, CMake Tools)
- Libraries: Qt, OpenCV
- Tests: Google Test; CI via GitHub Actions; smoke tests should run in CI.

## Exclusions

- RTSP stream generation
- Camera hardware control
- Server internal state management

---

# Server Requirements

## Responsibility

Server provides RTSP/H.264 video streams from camera or test sources and handles control commands from Client.

## Functional Requirements

- Provide RTSP/H.264 stream
- Accept and manage Client connections
- Validate and apply Frame Rate/Resolution control commands
- Provide clear success/failure responses and error states

## Environment & Build

- Target Runtime OS: Ubuntu
- Language: Java; Build: Gradle
- Windows environment used for additional verification where required

## Exclusions

- Client UI and rendering logic

---

# Common Requirements

## Responsibility

Shared contracts and common requirements both Client and Server must reference.

## Items
- Control command and response specifications
- Status and error codes
- RTSP URL formats
- Supported Frame Rate and Resolution ranges
- Version compatibility policy
- Interface contract: see `common/docs/interface_contract.md` (keep contract in `common/`)

---

# Integration & Cross-cutting

- Define and version the `common/docs/interface_contract.md` for protocol/payloads.
- Establish integration smoke tests that validate end-to-end connect/playback and control commands.
- CI must run Client build verification and smoke tests on changes.

---

# Change Log

- 2026-07-06: Consolidated per-project requirements into this file and deprecated per-project requirement files.
