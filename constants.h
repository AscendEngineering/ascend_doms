#pragma once

#include <string>

namespace constants{

    static const std::string from_drone = "5559";
    static const std::string to_worker = "5558";
    static const std::string from_worker = "5557";
    static const std::string to_drone = "5556";
    static const std::string video_port = "5555";
    

    static const std::string video_file = "/var/tmp/video_ip";

    //matches with enum in tables.sql
    enum status{
        AVAILABLE,
        IN_USE,
        REPAIR,
        RETIRED,
    };

    static const int max_waittime = 15;

}
