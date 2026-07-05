#include "camera_client/server_interface/mock_server_gateway.hpp"
#include "camera_client/system_info.hpp"
#include "camera_client/ui/client_controller.hpp"
#include "camera_client/ui/console_view.hpp"

#include <iostream>

int main()
{
    std::cout << camera_client::system_name() << '\n';

    camera_client::server_interface::MockServerGateway server_gateway;
    camera_client::ui::ClientController controller(server_gateway);
    camera_client::ui::ConsoleView view(controller, std::cout);

    return view.run_demo();
}
