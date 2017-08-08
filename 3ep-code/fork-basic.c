#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t childPid;

	childPid = fork();
	if (childPid == 0) {
		printf("in child(%d)\n", getpid());
		sleep(5);

	} else {
		printf("in parent(%d)\n", getpid());
	}

	return 0;
}