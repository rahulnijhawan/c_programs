#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define str(s) #s
#define xstr(s) str(s)
#define foo 6
int main(int argc, char const *argv[])
{
	if (argc !=2) {
		fprintf(stderr, "%s <error-constant>\n",argv[0] );
		exit(EXIT_FAILURE);
	}
	printf("%s, %i, %s\n", xstr("foo"), atoi(argv[1]),xstr(strtok(argv[1],"")) );
	printf("%s\n",strerror( atoi(argv[1])) );
	//printf("%s\n",strerror( (int) xstr(strtok(argv[1],""))) );
	return 0;
}
