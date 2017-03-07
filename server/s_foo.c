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


//// //// //// //// //// //// //// ////
// 
// Binds socket to port
//
// portno :: user supplied port
//
// on success => Return the socket file
//               des for the binded socket
//
// on failure => Terminate process and 
//               display error
int bind_sock(int portno)
{
    int sockfd, newsockfd;

    struct sockaddr_in serv_addr;

    // Open socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("[SYSTEM]: ERROR opening socket\nTerminating...\n");
        exit(sockfd);
    }
    
    // Define local addresses
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to this process
    if(bind(sockfd,(struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("[SYSTEM]: ERROR on binding\nTerminating...\n");
        exit(-1);
    }

    return sockfd;
}


//// //// //// //// //// //// //// ////
// 
// Listen for incoming connection requests
//
// sockfd :: binded socket to wait on
//
// on success => Return new sockfd for 
//               incoming communication
//
// on failure => Terminate process and 
//               display error
int listen_sock(int sockfd)
{
    int n_sockfd;
    socklen_t clilen;
    struct sockaddr_in cli_addr;

    // Wait for connection
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept connection
    n_sockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
    if(n_sockfd < 0)
    {
        printf("[SYSTEM]: ERROR on accept\nTerminating...\n");
        exit(-1);
    }

    return n_sockfd;
}


//// //// //// //// //// //// //// ////
//
// Retrieve message from client
//
// n_sockfd :: file des for connecting client
// message  :: message buffer to store in traffic
// size     :: buffer size in char
//
// on success => message is written to 
//               buffer
//
// on failure => Error is displayed and
//               process terminated
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
