#include <sys/types.h>

#include <sys/socket.h>
#include <arpa/inet.h>



#include <string.h>

#include "error.h"
int main(int argc, char const *argv[])
{
	// udp socket
	pid_t sockId = socket(AF_INET, SOCK_DGRAM, 0);

	if (sockId < 0) {
		err("socket open error:");
	}
	struct sockaddr_in sock_in;

	memset(&sock_in, 0, sizeof(sock_in));
	
	int portno = 3002;
	char *hostAddr = "127.0.0.1";
	sock_in.sin_family = AF_INET;
	sock_in.sin_port = htons(portno);
	sock_in.sin_addr.s_addr = inet_addr(hostAddr);
	if (connect(sockId, (const struct sockaddr*)&sock_in, sizeof sock_in) < 0) {
		err("Connect open error:");
	}


	return 0;
}
