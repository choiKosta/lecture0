#include "camera_client/system_info.hpp"

#include <iostream>

int main()
{
    std::cout << "Camera Client scaffold: " << camera_client::system_name() << '\n';
    return 0;
}
