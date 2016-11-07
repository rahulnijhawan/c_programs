#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // getpid, 
#include <string.h>

int main(int argc, char const *argv[])
{
	printf("hello word (pid:%d) \n", (int)getpid());
	int child = fork();
	if (child < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (child == 0) {
		printf("hello i'm child (pid:%d)\n",(int)getpid() );
		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("p3.c");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
		printf("this should not print out\n");
	} else {
		printf("Hello i'm parent of %d (pid:%d)\n",child, (int)getpid());
	}
	return 0;
}