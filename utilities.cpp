#include "utilities.h"
#include <string>
#include <iostream>
#include <chrono>
#include "spdlog/async.h"


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

    spdlog::init_thread_pool(8192, 1);
    
    //console logger
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    
    //file logger
    auto max_size = 1048576 * 5;
    auto max_files = 3;
    std::string filename = "logs/" + std::to_string(now_epoch()) + ".log";
    auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>( filename , max_size, max_files);
    
    std::vector<spdlog::sink_ptr> sinks {console_sink, file_sink};
    auto logger = std::make_shared<spdlog::async_logger>("base", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    spdlog::set_default_logger(logger);

}


long utilities::now_epoch(){
    const auto now = std::chrono::system_clock::now();
    const auto epoch   = now.time_since_epoch();
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);
    return seconds.count();
}




