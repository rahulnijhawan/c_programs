#include <stdio.h>
#include <stdlib.h>
//#include <error.h>

void err(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}