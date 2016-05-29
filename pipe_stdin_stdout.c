/*
	open pipe and replace read and write end with stdin and stdout.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "error.h"

int main(int argc, char const *argv[])
{
	int p_fd[2];
	pid_t ch_id;
	if (pipe(p_fd) == -1) {
		err("pipe.");
	}

	ch_id = fork();
	if (ch_id != 0){
		// child for writing
		close(p_fd[0]);
		dup2(STDIN_FILENO, p_fd[1]);
		char s[100];
		read(p_fd[1], (char *) s, 100);
		return 0;
	}

	// parent for reading
	close(p_fd[1]);
	dup2(STDOUT_FILENO, p_fd[0]);
	write(p_fd[0], )


	return 0;
}