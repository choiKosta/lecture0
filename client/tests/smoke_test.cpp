#include "camera_client/server_interface/mock_server_gateway.hpp"
#include "camera_client/system_info.hpp"
#include "camera_client/ui/client_controller.hpp"

#include <string>

int main()
{
    if (camera_client::system_name().empty()) {
        return 1;
    }

    camera_client::server_interface::MockServerGateway server_gateway;
    camera_client::ui::ClientController controller(server_gateway);

    if (controller.snapshot().connection_state != "Disconnected") {
        return 1;
    }

    if (!controller.connect_to_server({"localhost", 8554})) {
        return 1;
    }

    const auto connected_snapshot = controller.snapshot();
    if (connected_snapshot.connection_state != "Connected") {
        return 1;
    }

    if (connected_snapshot.stream_url.find("rtsp://localhost:8554") != 0) {
        return 1;
    }

    if (controller.change_frame_rate(30) != camera_client::server_interface::ControlResult::Accepted) {
        return 1;
    }

    if (controller.change_resolution(1920, 1080) != camera_client::server_interface::ControlResult::Accepted) {
        return 1;
    }

    controller.disconnect_from_server();
    return controller.snapshot().connection_state == "Disconnected" ? 0 : 1;
}
