#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define FIFO_FILE "MYFIFO"

int main(int argc, char *argv[])
{
        // FILE *fp;
        int fd;

        if ( argc != 2 ) {
                printf("USAGE: fifoclient [string]\n");
                exit(1);
        }

        if((fd = open(FIFO_FILE, O_WRONLY       )) == -1) {
                perror("open");
                exit(1);
        }

        // need to see is write send \0 as well????
        write(fd, argv[1], 80);
        write(fd, '\0', 1);
        printf("%s\n", argv[1]);
        close(fd);
        return(0);
}