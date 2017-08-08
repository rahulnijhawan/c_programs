#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define errmsg(msg) perror(msg); \
				 exit(EXIT_FAILURE);					
int main(int argc, char const *argv[]) {

	int sfd;
	struct addrinfo hints;
	struct addrinfo *res;

	if (argc !=2) {
		fprintf(stderr, "%s <domainname> [port]\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	sfd = socket(AF_INET, SOCK_STREAM, 110);
	if ( sfd == -1) {
		//printf("errorno %d\n", errno);
		errmsg("socket creation error");
	}

	memset(&hints, 0 , sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_protocol = 0;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = 0;
	
	getaddrinfo(argv[1], argv[2], &hints, &res);
	return 0;
}