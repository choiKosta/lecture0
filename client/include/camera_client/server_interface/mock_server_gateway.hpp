#pragma once

#include "camera_client/server_interface/server_gateway.hpp"

namespace camera_client::server_interface {

class MockServerGateway final : public IServerGateway {
public:
    bool connect(const ServerEndpoint& endpoint) override;
    void disconnect() override;
    ConnectionState connection_state() const override;
    StreamInfo stream_info() const override;
    ControlResult set_frame_rate(int frames_per_second) override;
    ControlResult set_resolution(int width, int height) override;
    std::string last_error() const override;

private:
    ConnectionState state_{ConnectionState::Disconnected};
    ServerEndpoint endpoint_{"", 0};
    std::string last_error_;
};

} // namespace camera_client::server_interface
