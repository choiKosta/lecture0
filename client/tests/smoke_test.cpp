#include "camera_client/system_info.hpp"

int main()
{
    return camera_client::system_name().empty() ? 1 : 0;
}

