#include <stdio.h>
#include <stdlib.h> //exit
#include <unistd.h> // getpid
#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{	
	printf("hello world: (pid %d)", (int) getpid());
	int cp = fork();
	if (cp < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (cp == 0) {
		printf("hello i'm child (pid:%d)\n",(int)getpid() );
		close(STDOUT_FILENO);
		open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		char *myargs[2];
		myargs[0] = strdup("echo");
		myargs[1] = strdup("echo me\n");
		execlp(myargs[0], (const char *) myargs[0], (const char *)myargs[1], NULL);
	} else {
		printf("Hello i'm parent of %d (pid:%d)\n",cp, (int)getpid());
	}
	return 0;
}