#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/mman.h>
void errorHandler() {
	perror("error:");
	exit(EXIT_FAILURE);
}

/*
	?????????????
	how to instance of program get the same file descriptor even they open different files
	mmap mmap-text1
	mmap mmap-text2 on different terminals
	???????????????????
*/
int main(int argc, char const *argv[])
{
	/* code */
	char c[] = "hi hello";
	if (argc == 1) {
		fprintf(stderr,"%s <file-name>", argv[0]);
		exit(EXIT_FAILURE);
	}
	int fd = open(argv[1], O_RDWR | O_CREAT,(S_IRWXU|S_IRWXG|S_IRWXO));
	if (fd == -1) {
		errorHandler();
	}

	write(fd,"data in");
	//printf("%d\n", fd);
	
	return 0;
}


