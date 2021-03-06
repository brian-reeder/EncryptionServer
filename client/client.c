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

#include "c_foo.h"

int main()
{
    int portno, sockfd, n;
    char msg[80];
    portno = 8080;

    // Establish Connection to server
    printf("[CLIENT]: Establishing connection with server.\n");
    sockfd = con_serv(portno);
    strncpy(msg, "Testing 1 2 3...", 80);
    
    // Send Message to Server
    printf("[CLIENT]: Preparing to send message to server.\n");
    n = write(sockfd, msg, strlen(msg));
    if(n < 0)
    {
        printf("[CLIENT]: ERROR writing to socket\nTerminating...\n");
        close(sockfd);
        exit(-1);
    }

    n = read(sockfd, msg, sizeof(char) * 80);
    if(n < 0)
    {
        printf("[SYSTEM]: ERROR reading from socket.\nTeminating...\n");
        close(sockfd);
        exit(-1);
    }
    printf("[SERVER]: %s\n", msg);

    // Close Socket
    printf("[CLIENT]: Closing socket.\n");
    close(sockfd);

    return 0;
}
