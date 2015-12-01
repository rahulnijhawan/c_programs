#include <stdio.h>
#include <unistd.h>

#define handle_error(msg) \
	perror(msg);

void main()
{
	handle_error("fstat");
	printf("%ld\n", sysconf(PAGESIZE));

}