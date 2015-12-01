#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char const *argv[])
{
	struct sockaddr *addr;
	char const *node, *service;
	struct addrinfo hints;
	struct addrinfo *res,*p;
	struct sockaddr_in *h;
	struct sockaddr_in6 *h6;
	int socFd = socket(AF_INET,SOCK_STREAM,0);
	if (socFd == -1) {
		perror("socket descriptor error");
	}
	node = argv[1];
	service = argv[2];
	memset(&hints, 0, sizeof(struct sockaddr));
	hints.ai_flags = 0;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	hints.ai_addrlen = 0;


	if (getaddrinfo(node,service,&hints,&res) != 0) {
		perror("error");
		exit(EXIT_FAILURE);
	}

	
	for (p = res; p!=NULL; p = p->ai_next) {
		
		
		
		if (p->ai_family == AF_INET) {
			h = (struct sockaddr_in *) p->ai_addr;
			char ip[INET_ADDRSTRLEN];	
			inet_ntop(p->ai_family, &h->sin_addr, ip,INET_ADDRSTRLEN);
			printf("IP4 -> %s\n", ip);
		} else {
			printf("IP6\n");
			char ip[INET6_ADDRSTRLEN];
			h6 = (struct sockaddr_in6 *) p->ai_addr;
			printf("%s\n",inet_ntop(p->ai_family, &h6->sin6_addr, ip,INET6_ADDRSTRLEN));
		}
		
		
		//printf("%s\n", inet_ntoa(h->sin_addr));
		
	}

	freeaddrinfo(res);

	printf("%d\n", socFd);
	return 0;
}