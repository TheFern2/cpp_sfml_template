#pragma once

#include <iostream>

namespace config
{
    extern std::string app_name;
    extern std::string version;

    bool load_config(std::string filename);
}