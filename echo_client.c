#include <sys/types.h>
#include <sys/socket.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

void err(char *);

#define USER_DATA_LEN 80
int main(int argc, char const *argv[])
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in sa_in;
	memset(&sa_in, 0, sizeof(sa_in));
	sa_in.sin_family = AF_INET;
	sa_in.sin_port = htons(3001);
	sa_in.sin_addr.s_addr = inet_addr("127.0.0.1");
	int conRes = connect(sfd, (const struct sockaddr *)&sa_in, sizeof(sa_in));
	//printf("%d\n", conRes);
	if (conRes != 0) {
		err("connection error");
	}
	char *s = (char *) malloc(sizeof(char)*USER_DATA_LEN);
	char const *str = argv[1];
	//read(stdin, *s, USER_DATA_LEN);
	write(sfd, str, sizeof(str));
	read(sfd, s, USER_DATA_LEN);
	printf("%s\n", s);
	return 0;
}

void err(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}