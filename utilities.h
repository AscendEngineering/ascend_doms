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
    
    //functions
    std::string resolveDNS(const std::string& url);
    std::string my_public_ip();
    void line_buffer(bool on = true);
    std::string get_term_input();
    long now_epoch();
    std::string timestamp();

    //vars
    const int STDIN = 0;
}






