# Unified Product Backlog

This file consolidates Client and Server product backlog items into a single, canonical backlog stored alongside the requirements.

Location of previous per-project backlogs:
- Client: `client/docs/product-backlog.md` (deprecated, see note below)
- Server: `server/docs/product-backlog.md` (deprecated, see note below)

## Overview

The backlog is organized by Epics and then by items. Each item includes an ID, description, and Acceptance Criteria. Items that affect both Client and Server are marked with `area: client, server`.

---

## Client Backlog Items

### Epic 1: Server connection and status

- CL-1: Server connection info input/selection
  - Provide UI to input/select Server URL, port, and optional authentication.
  - Acceptance Criteria:
    1. User can set Server connection info.
    2. Saved connection info can be reused.

- CL-2: Server connection handling
  - Send connection requests and handle success/failure.
  - Acceptance Criteria:
    1. Can connect to Server.
    2. Shows error on connection failure.

- CL-3: Connection status UI
  - Display connection states (connecting/connected/disconnected) and update UI on changes.
  - Acceptance Criteria:
    1. Distinct UI for connecting, connected, disconnected.
    2. UI updates immediately on state change.

### Epic 2: Video streaming display

- CL-4: RTSP/H.264 stream receive and display
  - Receive stream from Server and render in UI.
  - Acceptance Criteria:
    1. RTSP/H.264 stream plays correctly.
    2. Shows error when playback fails.

### Epic 3: Screen control commands

- CL-5: Frame Rate control command (client -> server)
  - User selects/inputs frame rate and Client sends control command to Server.
  - Acceptance Criteria:
    1. Client can send Frame Rate control command.
    2. Client handles Server response (success/failure).

- CL-6: Resolution control command (client -> server)
  - User selects/inputs resolution and Client sends control command to Server.
  - Acceptance Criteria:
    1. Client can send Resolution control command.
    2. Client handles Server response (success/failure).

### Epic 4: Error reporting and UX

- CL-7: Distinct error reporting
  - Provide clear error messages for connection, streaming, and control failures.
  - Acceptance Criteria:
    1. Different messages per error type.
    2. Provide actionable guidance to user.

### Epic 5: Build & verification

- CL-8: CMake build configuration
  - Ensure `camera_client` builds with CMake.
  - Acceptance Criteria:
    1. `cmake -S client -B client/build` succeeds.
    2. `cmake --build client/build` succeeds.

- CL-9: Tests and CI
  - Write tests (Google Test) and integrate with CI.
  - Acceptance Criteria:
    1. `ctest --test-dir client/build` succeeds.
    2. CI runs tests on client changes.

---

## Server Backlog Items

### Epic 1: RTSP streaming provision

- SR-1: RTSP/H.264 stream provisioning
  - Produce RTSP stream from camera or test source.
  - Acceptance Criteria:
    1. RTSP/H.264 stream is available.
    2. Client can receive the stream.

### Epic 2: Client connection management

- SR-2: Handle Client connection requests
  - Receive/manage client connection state.
  - Acceptance Criteria:
    1. Successfully accept connection requests.
    2. Handle disconnections/teardown.

### Epic 3: Control command handling

- SR-3: Frame Rate command receive & validation
  - Receive Frame Rate commands from Client and validate.
  - Acceptance Criteria:
    1. Commands can be received.
    2. Out-of-range values are rejected/handled.

- SR-4: Resolution command receive & validation
  - Receive Resolution commands and validate.
  - Acceptance Criteria:
    1. Commands can be received.
    2. Out-of-range values are rejected/handled.

- SR-5: Command result responses
  - Respond to Client with success/failure and clear status messages.
  - Acceptance Criteria:
    1. Responds with success/failure.
    2. Includes clear status messages.

### Epic 4: Error state management

- SR-6: Provide error state visibility
  - Maintain error state and expose to Client.
  - Acceptance Criteria:
    1. Error events are logged.
    2. Client can query/receive error details.

### Epic 5: Server operations

- SR-7: Ubuntu & Gradle execution environment
  - Build and run server on Ubuntu (Gradle).
  - Acceptance Criteria:
    1. `cd server && gradle build` succeeds.
    2. `cd server && gradle run` succeeds.

- SR-8: Windows verification records
  - Document Windows validation results on PRs where required.
  - Acceptance Criteria:
    1. Windows build/test results documented when needed.

---

## Cross-cutting / Integration Items

- INT-1: Define client-server interface contract
  - Use `common/docs/interface_contract.md` to specify protocol, payloads, and error semantics.
  - Acceptance Criteria:
    1. Interface contract exists and is versioned.
    2. Both Client and Server reference the contract in implementation.

- INT-2: Integration smoke tests
  - Basic end-to-end test that builds Client and Server (or uses test RTSP source) and validates connection + playback.
  - Acceptance Criteria:
    1. Smoke test runs and reports pass/fail in CI.

---

## Notes

- This file is the canonical product backlog. Per-project backlog files (`client/docs/product-backlog.md` and `server/docs/product-backlog.md`) are deprecated and should reference this file.
