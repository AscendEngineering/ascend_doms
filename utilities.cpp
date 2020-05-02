#include "utilities.h"



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







