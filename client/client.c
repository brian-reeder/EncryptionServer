//// //// //// //// //// //// //// ////
//
// Brian John Sedwick Reeder
// Reeder.BrianJ@gmail.com
//
// v0.1.1
// AES
// Server currently communicates via
// plaintext. only works on local
// network and on port 8080
// 
// 256-bit Key now generates 
// automatically
// 

#include "c_foo.h"

int main()
{
    // Client/Server Vars
    int portno, sockfd, n;
    char msg[256] = {0};
    portno = 8080;

    // Encryption Vars
    unsigned char* key;
    char buffer[256] = {0};

    // Establish Key for AES
    printf("[CLIENT]: Key = ");
    key = new_key();
    for(n = 0; n < 32; n++)
        printf("%x ", key[n]);
    printf("\n\n");

    // Retrieve Plaintext from user
    printf("[CLIENT]: Enter the Plain text to be encrypted [^D to end message]:\n>> ");
    while(fgets(buffer, 256, stdin) != NULL && printf(">> "))
        strncat(msg, buffer, 256);
    printf("^D\n\n");
   
    // Strip trailing newline from input
    msg[strlen(msg)-1] = '\0';
    printf("%s\n\n", msg); 

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
        exit(1);
    }
    
    // Recieve Response From Server
    n = read(sockfd, msg, sizeof(char) * 80);
    if(n < 0)
    {
        printf("[SYSTEM]: ERROR reading from socket.\nTeminating...\n");
        close(sockfd);
        exit(1);
    }
    printf("[SERVER]: %s\n", msg);

    // Close Socket
    printf("[CLIENT]: Closing socket.\n");
    close(sockfd);

    free(key);
    return 0;
}
