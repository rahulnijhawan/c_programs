#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char**argv)
{

	struct stat sstat;
	if (argc !=2) {
		fprintf(stderr,"Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (stat(argv[1], &sstat) == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}

	printf("inode number %ld\n",sstat.st_ino);
}