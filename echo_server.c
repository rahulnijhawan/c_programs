#include <stdio.h>
#include <stdlib.h>// for exit
#include <string.h>// for memset
/*
	socket, 
*/
#include <sys/types.h> //not need to include in posix.1-2001 and also not required in Linux(given in listen man page.
#include <sys/socket.h>

#include <arpa/inet.h>


#define BACKLOG 100

void err(char *msg);

int main(int argc, char const *argv[])
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);


	if (sfd == -1) {
		err("Socket opening error");
	}
	struct sockaddr_in sa_in;
	memset(&sa_in, 0, sizeof(sa_in));
	//struct sockaddr sa;
	int portno = 3001;
	sa_in.sin_family = AF_INET;
	sa_in.sin_addr.s_addr = INADDR_ANY;
	sa_in.sin_port = htons(portno);

	if (bind(sfd, (const struct sockaddr*) &sa_in, sizeof(sa_in)) < 0) {
		err("Can't bind address");
	}

	if (listen(sfd, BACKLOG) == -1) {
		err("Listen syscall error");
	}

	while(1) {
		int lsfd = accept(sfd, NULL, NULL);
		printf("get connection");
		if (lsfd != -1) {
			char str[50];
			read(lsfd, str, sizeof(str));
			printf("\n%s\n", str);
			write(lsfd, "hi client", 50);
		}
	}

	return 0;
}

void err(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}