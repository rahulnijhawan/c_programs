// #include <sys/types.h>
#include <sys/socket.h>


int main(int argc, char const *argv[])
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in sa_in;
	connect(sfd, (const sockaddr_in *)&sa_in, sizeof(sa_in));
	
	
	return 0;
}