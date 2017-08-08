#include <sys/socket>

#include <string.h>


int main(int argc, char const *argv[])
{
	struct sockaddr_un local, remote;

	int usfd = socket(AF_UNIX, SOCK_STREAM, 0);
	memset(&local, 0, sizeof(local));
	memset(&remote, 0, sizeof(remote));

	local.sun_family = AF_UNIX;
	local.sun_path = "";
	bind(usfd, local, sizeof(local));

	return 0;
}
