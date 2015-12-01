/*
	todo functions:
		1) setuid(), getuid()
		2) seteuid(), geteuid()
		3) setreuid()
		4) setgid(), getgid()
		5) setegid(), getegid()
		6) umask()
*/

#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>



#define DATA_SIZE 1024
int main(int argc, char *argv[])
{
	FILE *fp;
	int c;
	char dt[DATA_SIZE];
	if (argc != 2) {
		fprintf(stderr, "%s filepath\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1],"r");
	printf("uid: %u, euid: %u\n", getuid(), geteuid());
	if (fp == NULL) {
		perror("File error");
		exit(EXIT_FAILURE);
	}

	while(feof(fp) == 0) {
		c = fread(dt, sizeof(char), DATA_SIZE,fp);
		printf("%s\n", dt);
	}

	printf("%s\n", getlogin());
	

	return 0;
}