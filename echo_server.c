#include <stdio.h>
#include <stdlib.h>

/*
	socket, 
*/
//#include <sys/types.h> not need to include in posix.1-2001 and also not required in Linux(given in listen man page.
#include <sys/socket.h>

#define BACKLOG 100

void err(char *msg);

int main(int argc, char const *argv[])
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);


	if (sfd == -1) {
		err("Socket opening error");
	}
	struct sockaddr_in sa_in;
	struct sockaddr sa;

	bind(sfd, (const struct sockaddr*) &sa_in, sizeof(sa_in));

	if (listen(sfd, BACKLOG) == -1) {
		err("Listen syscall error");
	}

	while(1) {
		int lsfd = accept(sfd, &sa_in, sizeof(sa));
		if (lsfd != -1) {

		}
	}

	return 0;
}

void err(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}