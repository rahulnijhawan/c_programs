#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
int main()
{
	char *buf;
	printf("%s\n", getcwd(buf, PATH_MAX));
}