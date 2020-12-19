//
// Created by william on 12/17/20.
//

#include <stdio.h>
#include "tcp_server.h"
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>

// ----------------- Configuration Options
#define DOMAIN AF_INET         // The domain argument specifies a communication domain.
#define TYPE SOCK_STREAM       // Specifies the communication semantics.
#define PROTOCOL 6             // Specifies a particular protocol to be used with the socket.

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

int main(){
	// -------- Setup the tcp socket.
	int tcp_socket = socket(DOMAIN, TYPE, PROTOCOL); // Creates an endpoint for communication.

	// -------- Setup the socket address.
	struct sockaddr_in tcp_address;			// Used to define a socket address.
	tcp_address.sin_family = DOMAIN;		// Address family.
	tcp_address.sin_port = htons(0xAF12);		// Port number.
	tcp_address.sin_addr.s_addr = INADDR_ANY;	// Internet address.
	
	// -------- Assign the address to the socket.	
	bind(tcp_socket, (struct sockaddr*)&tcp_socket, sizeof(tcp_socket));

	printf("The program has completed\n");
	return 0;
}
