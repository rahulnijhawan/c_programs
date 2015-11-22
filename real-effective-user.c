#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("current user id %u, current effective id %u\n",getuid(),geteuid() );
	printf("current user id %u, current effective id %u\n",getgid(),getegid() );
	//printf("%s\n", );
	return 0;
}