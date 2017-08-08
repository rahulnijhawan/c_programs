#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	
	int child = fork();
	if (child < 0) {
		printf("not able to create child\n");
	} else if (child == 0) {
		printf("child(%d)\n", getpid());
	} else {
		wait(NULL);
		printf("parent(%d)\n", getpid());
	}
	return 0;
}