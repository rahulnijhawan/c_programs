#include <sys/socket.h>// socket

#include <string.h> // memset

#include <stdio.h> // printf


#include <arpa/inet.h> // inet_addr, inet_ntoa

#include <time.h>

#include "error.h"
#define BACKLOG 1


/*
	-- when i use a fixed port number for the client it reply once and after it could not response and server need to restart to send respond to client

	-- how i can keep one socket for long time and two process communicate each other. for example chat system

	-- how i can read data whenever available instead for busy-waiting/polling for data.(slect/poll?? can do work for me?)
*/
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
		shutdown(csfd, SHUT_WR);

		printf("Ip:port: %s:%d\n", inet_ntoa(sa_req.sin_addr), ntohs(sa_req.sin_port));
	}
	return 0;
}