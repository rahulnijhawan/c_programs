#include <stdio.h>
#include <stdlib.h>

/**
 *  /proc/{pid}/maps
 */

int main(int argc, char const *argv[])
{
	void *p = malloc(1);
    printf("%p\n", p);
	getchar();
	return EXIT_SUCCESS;
}