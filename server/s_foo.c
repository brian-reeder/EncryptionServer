#include "s_foo.h"

int bind_sock(int portno)
{
    int sockfd, newsockfd;

    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("[SYSTEM]: ERROR opening socket\nTerminating...\n");
        exit(sockfd);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd,(struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("[SYSTEM]: ERROR on binding\nTerminating...\n");
        exit(-1);
    }

    return sockfd;
}

int listen_sock(int sockfd)
{
    int n_sockfd;
    socklen_t clilen;
    struct sockaddr_in cli_addr;

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    n_sockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
    if(n_sockfd < 0)
    {
        printf("[SYSTEM]: ERROR on accept\nTerminating...\n");
        exit(-1);
    }

    return n_sockfd;
}


void fetch_message(int n_sockfd, char *message, int size)
{
    int n;

    n = read(n_sockfd, message, sizeof(char) * size);
    if(n < 0)
    {
        printf("[SYSTEM]: ERROR reading from socket\nTerminating...\n");
        exit(0);
    }
}
