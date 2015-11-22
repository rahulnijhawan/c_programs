#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	struct stat filestat;

	if (argc !=2) {
		fprintf(stderr, "Usage: %s path\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stat(argv[1],&filestat);
	printf("Inode \t\t%s \t%s\n","mode","File permision");
	printf("%ld \t%o \t%o\n", filestat.st_ino,(unsigned int)filestat.st_mode,(unsigned int)(filestat.st_mode & S_IFMT));
	return 0;
}