#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <boost/asio.hpp>
#include <boost/bind.hpp>



namespace utilities{
    std::string resolveDNS(const std::string& url);
    std::string my_public_ip();
    long now_epoch();
}






