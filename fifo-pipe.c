/*
	create producer and consummer using name pipe or FIFO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen
#include <sys/types.h> // getpid
#include <unistd.h> // getpid, unlink, execl
#include <sys/stat.h> // mkfifo, open
#include <fcntl.h> // open

#include "error.h"

#define is_child(pid) pid == 0? 1:0
#define FIFO_FILE "fifo_file"
#define FORK_CHILDREN 1

int main(int argc, char const *argv[])
{
	pid_t ch_pid = 0;
	int max_children = FORK_CHILDREN;

	/* IMPORTANT:
		test for file exists????
			-- access
				-- https://security.web.cern.ch/security/recommendations/en/codetools/c.shtml
			-- stat
			-- fstat
			-- lstat
	*/

	/*
		how can i print error with file name?????
		sticky bit???
	*/
	if (unlink(FIFO_FILE) != 0) {
		err("Error not able to remove fifo file");
	}

	if(mkfifo(FIFO_FILE, 0774) != 0) {
		err("Error not able to create fifo file");
	}
	// not checking errors here
	int ffd = open(FIFO_FILE, O_WRONLY);

	char buf[50] = "hi hello here.";
	write(ffd, buf, strlen(buf));

	
	/*
	not useful here can be used in anonymous pipe or related child sharing.
	while (max_children--) {
		ch_pid = fork();

		if (is_child(ch_pid)) {
			
			printf("Process id: %d \n", getpid());
			printf("max_children %d", max_children);
			// execl("pipe", "pipe", (char *) NULL);
			break;
		}
	}

	if(is_child(ch_pid)) {

	} else {

	}*/



	return 0;
}