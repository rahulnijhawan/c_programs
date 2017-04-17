#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int child = fork();

	if (child < 0) {

	} else if (child == 0) {
		close(STDOUT_FILENO);
		int fd = open("./redirec.ouput", O_WRONLY|O_CREAT, S_IRWXU|S_IRGRP|S_IROTH);
		printf("child\n");
	} else {
		printf("parent\n");
	}

	return 0;
}