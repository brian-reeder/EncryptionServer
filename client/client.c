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
    sockfd = con_serv(portno);
    strncpy(msg, "Testing 1 2 3...", 80);
    
    // Send Message to Server
    n = write(sockfd, msg, strlen(msg));
    if(n < 0)
    {
        printf("[CLIENT]: ERROR writing to socket\nTerminating...\n");
        close(sockfd);
        exit(-1);
    }

    // Close Socket
    close(sockfd);

    return 0;
}
