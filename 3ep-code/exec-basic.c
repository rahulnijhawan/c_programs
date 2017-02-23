/*
	Refer execve(2) for more detail.
*/
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int child = fork();

	if (child < 0) {
		printf("error\n");
	} else if (child == 0) {
		char *args[2];
		args[0] = "ls";
		args[1] = NULL;
		printf("child\n");
		execvp("ls", args);
	} else {
		printf("Parent\n");
	}
	return 0;
}