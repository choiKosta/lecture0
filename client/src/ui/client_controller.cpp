#include "camera_client/ui/client_controller.hpp"

namespace camera_client::ui {

ClientController::ClientController(server_interface::IServerGateway& server_gateway)
    : server_gateway_(server_gateway)
{
}

bool ClientController::connect_to_server(const server_interface::ServerEndpoint& endpoint)
{
    return server_gateway_.connect(endpoint);
}

void ClientController::disconnect_from_server()
{
    server_gateway_.disconnect();
}

server_interface::ControlResult ClientController::change_frame_rate(int frames_per_second)
{
    return server_gateway_.set_frame_rate(frames_per_second);
}

server_interface::ControlResult ClientController::change_resolution(int width, int height)
{
    return server_gateway_.set_resolution(width, height);
}

ClientSnapshot ClientController::snapshot() const
{
    const auto stream = server_gateway_.stream_info();

    return {
        server_interface::to_string(server_gateway_.connection_state()),
        stream.url,
        stream.codec,
        server_gateway_.last_error(),
    };
}

} // namespace camera_client::ui
