#include "c_foo.h"

int main()
{
    int portno, sockfd, n;
    char msg[80];
    portno = 8080;

    sockfd = con_serv(portno);
    strncpy(msg, "Testing 1 2 3...", 80);
    
    n = write(sockfd, msg, strlen(msg));
    if(n < 0)
    {
        printf("[CLIENT]: ERROR writing to socket\nTerminating...\n");
        close(sockfd);
        exit(-1);
    }

    close(sockfd);

    return 0;
}
