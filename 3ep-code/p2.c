#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // getpid, 
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	printf("hello word (pid:%d) \n", (int)getpid());
	int child = fork();
	if (child < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (child == 0) {
		printf("hello i'm child (pid:%d)\n",(int)getpid() );
	} else {
		int wc = wait(NULL);
		printf("Hello i'm parent of %d (wc:%d) (pid:%d)\n",child, wc, (int)getpid());
	}
	return 0;
}