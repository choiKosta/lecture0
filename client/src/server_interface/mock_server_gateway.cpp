#include "camera_client/server_interface/mock_server_gateway.hpp"

namespace camera_client::server_interface {

bool MockServerGateway::connect(const ServerEndpoint& endpoint)
{
    if (endpoint.host.empty() || endpoint.port <= 0) {
        last_error_ = "Invalid server endpoint";
        state_ = ConnectionState::Disconnected;
        return false;
    }

    endpoint_ = endpoint;
    last_error_.clear();
    state_ = ConnectionState::Connected;
    return true;
}

void MockServerGateway::disconnect()
{
    state_ = ConnectionState::Disconnected;
}

ConnectionState MockServerGateway::connection_state() const
{
    return state_;
}

StreamInfo MockServerGateway::stream_info() const
{
    if (state_ != ConnectionState::Connected) {
        return {"", ""};
    }

    return {"rtsp://" + endpoint_.host + ":" + std::to_string(endpoint_.port) + "/camera/main", "H.264"};
}

ControlResult MockServerGateway::set_frame_rate(int frames_per_second)
{
    if (state_ != ConnectionState::Connected) {
        last_error_ = "Frame rate command requires server connection";
        return ControlResult::Rejected;
    }

    if (frames_per_second < 1 || frames_per_second > 60) {
        last_error_ = "Frame rate must be between 1 and 60";
        return ControlResult::Rejected;
    }

    last_error_.clear();
    return ControlResult::Accepted;
}

ControlResult MockServerGateway::set_resolution(int width, int height)
{
    if (state_ != ConnectionState::Connected) {
        last_error_ = "Resolution command requires server connection";
        return ControlResult::Rejected;
    }

    if (width <= 0 || height <= 0) {
        last_error_ = "Resolution must be positive";
        return ControlResult::Rejected;
    }

    last_error_.clear();
    return ControlResult::Accepted;
}

std::string MockServerGateway::last_error() const
{
    return last_error_;
}

} // namespace camera_client::server_interface
