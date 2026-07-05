#pragma once

#include "camera_client/ui/client_controller.hpp"

#include <iosfwd>

namespace camera_client::ui {

class ConsoleView {
public:
    ConsoleView(ClientController& controller, std::ostream& output);

    int run_demo();

private:
    void print_snapshot(const char* title) const;

    ClientController& controller_;
    std::ostream& output_;
};

} // namespace camera_client::ui
