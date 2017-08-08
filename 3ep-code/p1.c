#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // getpid, 


int main(int argc, char const *argv[])
{
	printf("hello word (pid:%d) \n", (int)getpid());
	int child = fork();
	if (child < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (child == 0) {
		printf("hello i'm child (pid:%d), parent id (ppid: %d)\n",(int)getpid(), (int)getppid() );

	} else {
		printf("Hello i'm parent of %d (pid:%d), parent id (ppid: %d)\n",child, (int)getpid(), (int)getppid());
	}
	return 0;
}