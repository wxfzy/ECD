#include <stdio.h>
#include "tcp_server.h"
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <limits.h>

// ----------------- Configuration Options
#define DOMAIN AF_INET  // The domain argument specifies a communication domain.
#define TYPE SOCK_STREAM    // Specifies the communication semantics.
#define PROTOCOL 6  // Specifies a particular protocol to be used with the socket.

int main (){
    int i;  // Used as an iterator.
    int maxi = 0;   // Contains the largest index of the client array currently in use.
    int listenfd; //
    int connfd; // Used to store an accepted client.
    int sockfd; // Used to store a clients fd.
    int nready; // Used to store the number of elements in pollfds that have events or errors.
    ssize_t n; // Used to store count of bytes received from client.
    char buf[MAXLINE]; // Buffer to store incoming data.
    socklen_t clilen; // Because sockets _needs_ it's own integer type.
    struct pollfd client[OPEN_MAX]; // Used to store all of the connections fds.
    struct sockaddr_in clienaddr; // Used to store the connected client's internet address.
    struct sockaddr_in serveraddr; // Used to store our internet address.

    // -------- Create the TCP socket.
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // -------- Create the address for the TCP socket.
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SERV_PORT);

    // -------- Assign the address to the TCP socket.
    bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr));

    // -------- Setup the TCP socket for listening.
    listen(listenfd, LISTENQ);

    // -------- Set the first element in the client array to the TCP socket.
    client[0].fd = listenfd;
    client[0].events = POLLRDNORM;

    // -------- Set all of the other elements in the array as available (-1).
    for(i = 1; i < OPEN_MAX; i++)
        client[i].fd = -1;

    // Begin the infinite loop.
    for ( ;; ){

        nready = poll(client, maxi + 1, INFTIM);

        if (client[0].revents & POLLRDNORM){
            clilen = sizeof(clienaddr);
            connfd = accept(listenfd, (SA *) &cliaddr, &clilen);

            for (i = 1; i < OPEN_MAX; i++)
                if (client[i].fd < 0) {
                    client[i].fd = connfd;
                    break;
                }
            if (i == OPEN_MAX)
                err_quit("Too many clients");
            client[i].events = POLLRDNORM;
            if (i > maxi)
                maxi = i;
            if (--nread <= 0)
                continue;
        }

        for (i = 1; i <= maxi; i++) {
            if ((sockfd = client[i].fd) < 0)
                continue;
            if (client[i].revents & (POLLRDNORM | POLLERR)) {
                if ((n = read(sockfd, buf, MAXLINE)) < 0) {
                    if (errno == ECONNRESET) {
                        close(sockfd);
                        client[i].fd = -1;
                    } else
                        err_sys("Read error");
                } else if (n == 0) {
                    close(sockfd);
                    client[i].fd = -1;
                } else
                    writen(sockfd, buf, n);
                if (--nready <= 0 )
                    break;
            }
        }
    }
}