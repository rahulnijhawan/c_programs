#include <stdio.h>


#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <pwd.h>


int main(int argc, char const *argv[])
{
	char const *name = NULL;
	struct passwd *pwd;

	if (argc == 2) {
		name = argv[1];
	}

	uid_t r = 0;
	printf("%s\n", name);
	printf("user id:%u, user effective id:%u\n",getuid(),geteuid());
	printf("group id:%u, group effective id:%u\n",getgid(),getegid());

	pwd = getpwnam(name);
	if (pwd == NULL) {
		printf("getpwnam return null\n");
		exit(EXIT_FAILURE);
	}
	
	if (seteuid(pwd->pw_uid) == -1) {
		perror("setuid error");
	}

	printf("After calling setuid system call\n");
	printf("user id:%u, user effective id:%u\n",getuid(),geteuid());	
	printf("group id:%u, group effective id:%u\n",getgid(),getegid());	


	return 0;
}