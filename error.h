#ifndef _STDIO_H
	#include <stdio.h>
#endif
#ifndef _STDLIB_H 
	#include <stdlib.h>
#endif

void err(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}