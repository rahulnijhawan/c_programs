#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "error.h"
#include <string.h>

int main(int argc, char const *argv[])
{
	long long int li = 1;
	short int si = 1;
	int sfd = socket(PF_INET, SOCK_STREAM, 0);
	//printf("%u, sizeof %zu, ntohs(256) %u\n",htons(si), sizeof(si), ntohs(256));
	//printf("%u, sizeof %zu, ntohs(256) %u\n",htonl(li), sizeof(li), ntohl(16777216));
	struct sockaddr_in sa_in,sa_my;
	// check it define struct and data alignment
	
	memset(&sa_in, 0, sizeof(sa_in));
	
	memset(&sa_my, 0, sizeof(sa_in));
	sa_my.sin_family = PF_INET;
	sa_my.sin_port = htons(3000);
	sa_my.sin_addr.s_addr = inet_addr("127.0");
	if (bind(sfd, (const struct sockaddr*)&sa_my, sizeof(sa_my)) < 0) {
		err("bind failed");
	}

	printf("%s\n", inet_ntoa(sa_my.sin_addr)); 
	
	sa_in.sin_family = PF_INET;
	sa_in.sin_port = htons(13);
	sa_in.sin_addr.s_addr = inet_addr("127.0.0.1");
// google	sa_in.sin_addr.s_addr = inet_addr("216.58.196.110");

	if (connect(sfd, (const struct sockaddr *)&sa_in, sizeof(sa_in))) {
		err("connect failed");
	}
	#define BUFFER 1000
	char *buf = (char *) malloc(sizeof(char)*BUFFER);
	//fgets(buf, BUFFER, stdin);
	//printf("%s\n", buf);
	shutdown(sfd, SHUT_RD);
	//write(sfd, buf, BUFFER);
	read(sfd, buf, BUFFER);
	printf("%s\n", buf);

	return 0;
	
}
/*
	 00000001 00000000

	
*/