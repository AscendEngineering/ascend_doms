#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>


namespace utilities{
    std::string resolveDNS(const std::string& url);
    void setup_logging();
    long now_epoch();
}






