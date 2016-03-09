#include <sys/socket.h>// socket

#include <string.h> // memset

#include <arpa/inet.h>

#define BACKLOG 100

int main(int argc, char const *argv[])
{
	int sfd = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in sa_in;
	memset(&sa_in, 0, sizeof(sa_in));
	sa_in.sin_family = PF_INET;
	sa_in.sin_port = htons(13);
	sa_in.sin_addr.s_addr = inet_addr("192.168.1.2");
	bind(sfd, (const struct sockaddr *)&sa_in, sizeof(sa_in));

	listen(sfd, BACKLOG);
	return 0;
}