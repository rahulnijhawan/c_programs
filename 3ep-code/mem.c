#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "3ep/Intro/code/common.h"

int main(int argc, char const *argv[])
{
	int *intP = malloc(sizeof(int));
	assert(intP != NULL);

	printf("(%d) address pointed to by p: %p\n",getpid(), intP );

	*intP = 0;

	while(1) {
		Spin(1);
		*intP = *intP + 1;
		printf("(%d) p: %d\n", getpid(), *intP );
	}
	return 0;
}