#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#include <arpa/inet.h>

#include "error.h"


#define BACKLOG 100

int main(int argc, char const *argv[])
{
	struct sockaddr_in sockin;

	pid_t sockId = socket(AF_INET, SOCK_DGRAM,0);

	if (sockId == -1){
		err("Error Socket open");
	}

	int portno = 3002;
	memset(&sockin, 0, sizeof(sockin));
	sockin.sin_family = AF_INET;
	sockin.sin_addr.s_addr = INADDR_ANY;
	sockin.sin_port = htons(portno);

	if (bind(sockId, (const struct sockaddr *) &sockin, sizeof(sockin)) < -1) {
		err("Error while binding address");
	}
	if (listen(sockId, BACKLOG) < 0) {
		err("listen error");
	}
	// accept not work of UDP only work for (SOCK_STREAM, SOCK_SEQPACKET)
	if (accept(sockId, NULL, NULL) < 0) {
		err("accept error");
	}


	return 0;
}