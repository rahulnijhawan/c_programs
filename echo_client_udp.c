#include <sys/types.h>

#include <sys/socket.h>


#include <string.h>

#include "error.h"
int main(int argc, char const *argv[])
{
	// udp socket
	pid_t sockId = sokect(AF_INET, SOCK_DGRAM, 0);

	if (sockId < 0) {
		err("socket open error:");
	}
	struct sockaddr_in sock_in;
	memset(&sock_in, 0, sizeof(sock_in));
	
	if (connect(sockId, (const struct sockaddr*)&sock_in, sizeof sock_in) < 0) {
		err("Connect open error:");
	}


	return 0;
}
