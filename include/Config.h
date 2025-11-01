#pragma once
#include <string>

namespace config {
    extern std::string app_name;
    extern std::string version;

    bool load_config(const std::string& filename);
}