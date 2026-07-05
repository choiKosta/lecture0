#include "camera_client/server_interface/server_gateway.hpp"

namespace camera_client::server_interface {

std::string to_string(ConnectionState state)
{
    switch (state) {
    case ConnectionState::Disconnected:
        return "Disconnected";
    case ConnectionState::Connected:
        return "Connected";
    }

    return "Unknown";
}

std::string to_string(ControlResult result)
{
    switch (result) {
    case ControlResult::Accepted:
        return "Accepted";
    case ControlResult::Rejected:
        return "Rejected";
    }

    return "Unknown";
}

} // namespace camera_client::server_interface
