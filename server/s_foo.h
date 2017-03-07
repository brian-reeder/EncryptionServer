
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int bind_sock(int portno);
int listen_sock(int sockfd);
void fetch_message(int n_sockfd, char *message, int size);
