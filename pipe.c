/**
	1) pipe()
	2) fork()
	3) dup()
	4) dup2()
	5) exec()
	6) execlp
	7) popen()
	8) pclose()
	9) mknod()
	10) mkififo: shell cmd
	11) mknod: shell cmd
	12) umask()
	13) umask: shell cmd
	
*/

/*
	
	

	parent is reader and child is writer
	child: CRD -child read file descriptior, CWD -child write file descriptor
	child: PRD -parent read file descriptior, PWD -parent write file descriptor
		CRD	CWD	PRD	PWD
	1)	0	0	0	0	-All descriptor are close. output- reader: EOF, Writer: bad file descriptor
	2)	0	0	0	1 	-parent write descriptor is open. output- reader: EOF, Writer: bad file descriptor
	3)	0	0	1 	0	-parent read descriptor is open. output- reader: EOF, Writer: bad file descriptor
	4)	0	0	1 	1 	-parent read and write descriptor are open. output- reader: block, writer: bad file
						 descriptor
	5)	0	1 	0	0   -child write descriptor is open. output- reader: EOF, writer: SIGPIPE
	6)	0	1 	0	1 	-child write and parent write descriptor is open
	7)	0	1 	1 	0	-child write and parent read descriptor is open
	8)	0	1 	1 	1 	-child write descriptor is open. parent read and write descriptor is open
	9)	1 	0	0	0	-child read descriptor is open
	10)	1 	0	0	1 	-child read and parent write descriptor is open
	11)	1 	0	1 	0	-child and parent read descriptor is open
	12)	1 	0	1 	1 	-child read descritor is open, parent read and write descriptor is open
	13)	1 	1 	0	0	-child read and write descriptor is open 
	14)	1 	1 	0	1 	-child read and write descriptor are open. parent write descriptor is open
	15)	1 	1 	1 	0	-child read and write descriptor is open . parent read descriptor is open
	16)	1 	1 	1 	1 	-All descriptors are open

	Tasks to do
	1) test when all read are close what will happen while write.
	2) test when all write are closed what will happen while read.
	3) non blocking read and write as if pipe is empty read is blocked and if pipe is full write is blocked.
	   EPIPE, SIGPIPE.
	4) how to run more than 1 read and write processes and on different terminals(is this possible?i don't think
	   as it need common ancestral).

	
*/
 // trigraph and digraph: Will the next line be executed????????????????

// include guard: remove possiblity for include double inculsion of files, functions,structure

#ifndef GUARD_INCULDE
	#define GUARD_INCULDE
	//#error "not supported"
	// include file
#endif

// can only be used in included files #pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
//#include <fcntl.h> need for dup3(...)


void error_handler(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void sig_handler(int signum)
{
	printf("%d\n", signum);
}

//signal(SIGPIPE, sig_handler);

int main()
{

	int fd[2];
		pid_t cpid;
	char readbuf[20];
	/*
		pipe return 2 descriptor
			1) at index 0 is for read.
			2) at index 1 is for write.
	*/
	struct d;
	typedef struct d a;
	///??/<% %>
	if (pipe(fd) == -1) {
		perror("Pipe not open");
		exit(EXIT_FAILURE);
	}

	printf("ist fd: %ld, ist fd[0] again: %ld,   2nd fd[1] %ld\n", (long)fd,(long) &fd[0], (long)&fd[1]);
	int c;
	getc(stdin);
	if ((cpid = fork()) == -1) {
		perror("child not creating");
		exit(EXIT_FAILURE);
	}
	char *dt = "ra\0";// = "rahul nijhawan is fool\n";
	if (cpid == 0) {
		// child use as a writer
		close(fd[0]);
		//close(fd[1]); 
		//close(stdout);
		//dup(fd[1]);
		printf("parent process and child process id is \n");
		int i = 0;
		while(i < 10) {
			dt = (char *) malloc(sizeof(char)*20);
			dt[0] = 48+i;
			dt[1] = '\0';
			i++;
			//printf("%zd, %s\n", strlen(dt),dt);

			int c = write(fd[1], dt, strlen(dt)+1);
			 //fputc(i, fd[1]);	
			if (c == -1) {
				error_handler("cannot write");
			}
			//printf("%s\n",dt );
		}
		//close(fd[1]);
		//printf("child p: data count-%d\n", c);
	} else {	
		// parent use as a reader 
		//return 0;
		printf("parent process and child process id is %d\n", cpid);
		//close(fd[0]);
		close(fd[1]);
		dup2(0,fd[0]);
		execlp("sort", "sort", NULL);
		int i = 0;
		while(1) {
			//read(fd[0],readbuf, sizeof(readbuf));
			if (read(fd[0],readbuf, strlen(dt)+1) > 0) {
				printf("%zd data read: %s, %s\n", strlen(dt),readbuf,dt);
			} 
			else {
				printf("%zd\n",strlen(dt));
				break;
			}
		}


	}
	return 0;
}


char * readfile(char* filename)
{

}