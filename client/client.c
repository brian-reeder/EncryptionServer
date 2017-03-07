#include "c_foo.h"

int main()
{
    int portno, sockfd;
    char msg[80];
    portno = 8080;

    sockfd = con_serv(portno);
    strncpy(msg, "Testing 1 2 3...", 80);

    
    return 0;
}
