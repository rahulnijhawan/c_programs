#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	long long int li = 1;
	short int si = 1;
	int sfd = socket(PF_INET, SOCK_STREAM, 0);
	printf("%u, sizeof %zu, ntohs(256) %u\n",htons(si), sizeof(si), ntohs(256));
	printf("%u, sizeof %zu, ntohs(256) %u\n",htonl(li), sizeof(li), ntohl(16777216));
	return 0;
}
/*
	 00000001 00000000

	
*/