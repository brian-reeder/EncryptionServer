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

//// //// //// //// //// //// //// ////
//
// Establish a connection with the server
//
// portno :: user supplied port to connect to
//
// on success => returns file des for 
//               connected socket
//
// on failure => display error and safely
//               terminate the process
int con_serv(int portno)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Open socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("[CLIENT]: ERROR creating a socket\nTerminating...");
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


// Needs modification for 128bit 192bit & 256bit
unsigned char* new_key()
{
    int i;
    time_t t;
    unsigned char *key;
    
    // Seed the random number generator
    srand((unsigned) time(&t));

    // Create global space for new key
    key = (unsigned char *) malloc(sizeof(unsigned char) * 32);
    
    // Assign random values from 0x01 - 0xff
    for(i = 0; i < 32; i++)
        while(key[i] == 0)
            key[i] = rand() % 256;

    return key;
}
