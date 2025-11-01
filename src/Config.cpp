#include <json/json.h>
#include <json/value.h>
#include <fstream>
#include "spdlog/spdlog.h"
#include "Config.h"

namespace config
{
    std::string app_name;
    std::string version;
}

bool config::load_config(const std::string& filename)
{
    if (std::ifstream file(filename); file.good())
    {
        Json::Value json;
        Json::Reader reader;
        reader.parse(file, json);

        app_name = json["app_name"].asString();
        version = json["version"].asString();

        return true;
    }
    else {
        spdlog::error("Configuration file not found");
        return false;
    }
}