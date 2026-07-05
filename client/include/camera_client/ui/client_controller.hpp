#pragma once

#include "camera_client/server_interface/server_gateway.hpp"

#include <string>

namespace camera_client::ui {

struct ClientSnapshot {
    std::string connection_state;
    std::string stream_url;
    std::string codec;
    std::string last_error;
};

class ClientController {
public:
    explicit ClientController(server_interface::IServerGateway& server_gateway);

    bool connect_to_server(const server_interface::ServerEndpoint& endpoint);
    void disconnect_from_server();
    server_interface::ControlResult change_frame_rate(int frames_per_second);
    server_interface::ControlResult change_resolution(int width, int height);
    ClientSnapshot snapshot() const;

private:
    server_interface::IServerGateway& server_gateway_;
};

} // namespace camera_client::ui
