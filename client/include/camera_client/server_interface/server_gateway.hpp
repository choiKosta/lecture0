#pragma once

#include <string>

namespace camera_client::server_interface {

enum class ConnectionState {
    Disconnected,
    Connected,
};

struct ServerEndpoint {
    std::string host;
    int port;
};

struct StreamInfo {
    std::string url;
    std::string codec;
};

enum class ControlResult {
    Accepted,
    Rejected,
};

class IServerGateway {
public:
    virtual ~IServerGateway() = default;

    virtual bool connect(const ServerEndpoint& endpoint) = 0;
    virtual void disconnect() = 0;
    virtual ConnectionState connection_state() const = 0;
    virtual StreamInfo stream_info() const = 0;
    virtual ControlResult set_frame_rate(int frames_per_second) = 0;
    virtual ControlResult set_resolution(int width, int height) = 0;
    virtual std::string last_error() const = 0;
};

std::string to_string(ConnectionState state);
std::string to_string(ControlResult result);

} // namespace camera_client::server_interface
