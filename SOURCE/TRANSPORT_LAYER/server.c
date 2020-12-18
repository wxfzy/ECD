//
// Created by william on 12/17/20.
//

#include "server.h"
#include <sys/socket.h>
#include <sys/epoll.h>

/*--------- Socket Configuration Options --------*/
static int const DOMAIN = AF_INET;         // The domain argument specifies a communication domain.
static int const TYPE = SOCK_STREAM;       // Specifies the communication semantics.
static int const PROTOCOL = 6;             // Specifies a particular protocol to be used with the socket.

// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
// int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
// int listen(int sockfd, int backlog);
// int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
// epoll_create1(2)
// epoll_ctl(2)
// epoll_wait(2)
// send(2), sendto(2), and sendmsg(2)
// recv(2), recvfrom(2), recvmsg(2)
// int close(int fd);

/*
 * 1. Initialize variables.
 * 2. Create master socket.
 * 3. Bind.
 * 4. Listen.
 * 5. Initialize and fill readfds.
 * 6. Select.
 * 7. Accept the connection.
 * 8. Service the client requests.
 * 9. Close the connection.
 * 10 .
 */

int server_controller(){
    return 0;
}


epoll_create1(2)
epoll_ctl(2)
epoll_wait(2)