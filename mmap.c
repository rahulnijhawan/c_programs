#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define CHARBYTES 1
#define CHARLENGHT 80
void err(char *msg);

int main(int argc, char const *argv[])
{
	char *addr;
	int offset = 0;
	if (argc !=2) {
		fprintf(stderr, "%s <filename>\n",argv[0] );
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1) {
		err("file can't open");
	}
	printf("%ld\n",sysconf(_SC_PAGESIZE));
	addr = mmap(NULL, CHARBYTES*CHARLENGHT, PROT_READ, MAP_SHARED, fd, offset * sysconf(_SC_PAGESIZE));
	if (addr == MAP_FAILED) {
		err("mmap");
	}
	write(STDOUT_FILENO, addr, CHARBYTES*CHARLENGHT );
	printf("\n");
	write(STDOUT_FILENO, addr, CHARBYTES*CHARLENGHT -10 );
	printf("\n");
	return 0;
}

void err(char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}