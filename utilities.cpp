#include "utilities.h"
#include <string>
#include <iostream>
#include <chrono>
#include <cctype>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <curl/curl.h>

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>

using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http;    // from <boost/beast/http.hpp>

bool is_ip(const std::string& url){
    for(auto character: url){
        bool ip_char = isdigit(character) || character=='.';
        if(!ip_char){return false;}
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

std::string utilities::my_public_ip(){

    std::string command("curl -s ifconfig.me 2>&1");

    std::array<char, 128> buffer;
    std::string result;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Couldn't start command." << std::endl;
        return "";
    }
    while (fgets(buffer.data(), 128, pipe) != NULL) {
        result += buffer.data();
    }
    auto returnCode = pclose(pipe);
    return result;
}


long utilities::now_epoch(){
    const auto now = std::chrono::system_clock::now();
    const auto epoch   = now.time_since_epoch();
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);
    return seconds.count();
}




