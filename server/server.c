//
// Brian John Sedwick Reeder
// Reeder.BrianJ@gmail.com
//
//

#include "s_foo.h"

#define BUF_SIZE 256

int main()
{

    int sockfd, n_sockfd, portno, n;

    socklen_t clilen;
    
    struct sockaddr_in serv_addr, cli_addr;

    char message[BUF_SIZE] = {0};

    portno = 8080;

    printf("[SYSTEM]: Binding server to port number %i\n", portno);
    sockfd = bind_sock(portno);

    printf("[SYSTEM]: Listening for a connecting client...");
    n_sockfd = listen_sock(sockfd);
    
    fetch_message(n_sockfd, message, BUF_SIZE);
   
    printf("%s\n", message);
 
    close(n_sockfd);
    close(sockfd);
    return 0;
}
