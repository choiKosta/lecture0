#include "camera_client/ui/console_view.hpp"

#include "camera_client/server_interface/server_gateway.hpp"

#include <ostream>

namespace camera_client::ui {

ConsoleView::ConsoleView(ClientController& controller, std::ostream& output)
    : controller_(controller)
    , output_(output)
{
}

int ConsoleView::run_demo()
{
    output_ << "Camera Client prototype\n";

    print_snapshot("Initial");

    const auto connected = controller_.connect_to_server({"127.0.0.1", 8554});
    output_ << "Connect command: " << (connected ? "Success" : "Failed") << '\n';
    print_snapshot("After connect");

    const auto frame_rate_result = controller_.change_frame_rate(30);
    output_ << "Frame rate command: " << server_interface::to_string(frame_rate_result) << '\n';

    const auto resolution_result = controller_.change_resolution(1280, 720);
    output_ << "Resolution command: " << server_interface::to_string(resolution_result) << '\n';

    controller_.disconnect_from_server();
    print_snapshot("After disconnect");

    return connected ? 0 : 1;
}

void ConsoleView::print_snapshot(const char* title) const
{
    const auto snapshot = controller_.snapshot();

    output_ << '[' << title << "]\n"
            << "State: " << snapshot.connection_state << '\n'
            << "Stream: " << (snapshot.stream_url.empty() ? "-" : snapshot.stream_url) << '\n'
            << "Codec: " << (snapshot.codec.empty() ? "-" : snapshot.codec) << '\n';

    if (!snapshot.last_error.empty()) {
        output_ << "Error: " << snapshot.last_error << '\n';
    }
}

} // namespace camera_client::ui
