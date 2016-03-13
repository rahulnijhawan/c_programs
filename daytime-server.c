#include <sys/socket.h>// socket

#include <string.h> // memset

#include <stdio.h> // printf


#include <arpa/inet.h> // inet_addr, inet_ntoa

#include <time.h>

#include "error.h"
#define BACKLOG 1

int main(int argc, char const *argv[])
{
	int sfd = socket(PF_INET, SOCK_STREAM, 0);
	int sa_req_size;
	struct sockaddr_in sa_in, sa_req;
	memset(&sa_in, 0, sizeof(sa_in));
	sa_in.sin_family = PF_INET;
	sa_in.sin_port = htons(13);
	sa_in.sin_addr.s_addr = INADDR_ANY;//inet_addr("192.168.137.98");
	if (bind(sfd, (const struct sockaddr *)&sa_in, sizeof(sa_in)) < 0) {
		err("Bind failed");
	}

	
	
	listen(sfd, BACKLOG);
	int csfd;
	while(1) {
		csfd = accept(sfd, (struct sockaddr *)&sa_req, &sa_req_size);
		time_t curtime = time(NULL);
		char *t =	ctime(&curtime);
		write(csfd, t, 1000);

		printf("%s\n", inet_ntoa(sa_req.sin_addr));
	}
	return 0;
}