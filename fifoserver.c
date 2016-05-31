#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <linux/stat.h>

#include "error.h"

#define FIFO_FILE "MYFIFO"

int main(void)
{
        FILE *fp;
        int fd;
        char readbuf[80];

        /* Create the FIFO if it does not exist */
        umask(0);
        mknod(FIFO_FILE, S_IFIFO|0666, 0);

        while(1)
        {
                fd = open(FIFO_FILE, O_CREAT|O_RDONLY);
                if(fd == -1) {
                        err("open");
                }
                        
                read(fd, readbuf, 80);
                //fgets(readbuf, 80, fp);
                printf("Received string: %s\n", readbuf);
                close(fd);
                
        }

        return(0);
}