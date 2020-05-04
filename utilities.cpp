#include "utilities.h"
#include <string>
#include <iostream>
#include <chrono>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"



bool is_ip(const std::string& url){
    for(auto character: url){
        if(isalpha(character)){return false;}
    }
    return true;
}

std::string utilities::resolveDNS(const std::string& url){
    std::string retval = "";

    if(!is_ip(url)){
        struct hostent *hp = gethostbyname(url.c_str());
        if(hp!=nullptr){
            retval = inet_ntoa( *( struct in_addr*)( hp -> h_addr_list[0]));
        }
        else{
            retval = url;
        }
    }
    else{
        retval = url;
    }

    return retval;
}


void utilities::setup_logging(){
    auto max_size = 1048576 * 5;
    auto max_files = 3;
    std::string filename = "logs/" + std::to_string(now_epoch()) + ".log";
    auto logger = spdlog::rotating_logger_mt("base", filename , max_size, max_files);
    spdlog::set_default_logger(logger);
}


long utilities::now_epoch(){
    const auto now = std::chrono::system_clock::now();
    const auto epoch   = now.time_since_epoch();
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);
    return seconds.count();
}




