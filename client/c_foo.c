#include "c_foo.h"

int con_serv(int portno)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("[CLIENT]: ERROR creating a socket\n");
        exit(-1);
    }

    // Defines local address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Connecting to the server
    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0 )
    {
        printf("[CLIENT]: ERROR while attempting to connect\nTerminating...\n");
        exit(-1);
    }

    return sockfd;
}
