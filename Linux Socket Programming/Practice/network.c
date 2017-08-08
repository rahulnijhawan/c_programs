#include <stdio.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>

void handleError(char *);

int main(int argc, char const *argv[])
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(sfd == 1) {
		handleError("Can not open socket");
	}

	return 0;
}

void handleError(char *errorstr)
{
	perror(errorstr);
	exit(EXIT_FAILURE);
}