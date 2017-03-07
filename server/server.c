//// //// //// //// //// //// //// ////
//
// Brian John Sedwick Reeder
// Reeder.BrianJ@gmail.com
//
// v0.1.0
// Plain Text
// Server currently communicates via
// plaintext. only works on local
// network and on port 8080
// 

#include "s_foo.h"

#define BUF_SIZE 256

int main()
{

    int sockfd, n_sockfd, portno, n;
    socklen_t clilen;  
    struct sockaddr_in serv_addr, cli_addr;
    char msg[BUF_SIZE] = {0};

    portno = 8080;

    // Bind server to port
    printf("[SYSTEM]: Binding server to port number %i\n", portno);
    sockfd = bind_sock(portno);

    // Wait for an incoming connection
    printf("[SYSTEM]: Listening for a connecting client...\n");
    n_sockfd = listen_sock(sockfd);
    
    // Recieve message
    fetch_message(n_sockfd, msg, BUF_SIZE);
    printf("[CLIENT]: %s\n", msg);

    printf("[SYSTEM]: Responding to message.\n");
    strncpy(msg, "I have recieved your message.", BUF_SIZE);
    n = write(n_sockfd, msg, strlen(msg));

    if(n < 0)
    {
        printf("[SYSTEM]: Error writing to socket.\nTerminating...\n");
        close(n_sockfd);
        close(sockfd);
        exit(-1);
    } 
 
    // Exit Service
    printf("[SYSTEM]: Closing socket.\n");
    close(n_sockfd);
    close(sockfd);
    return 0;
}
