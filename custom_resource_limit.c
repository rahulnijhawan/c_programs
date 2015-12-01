#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>

// struct rlimit {
//            rlim_t rlim_cur;  /* Soft limit */
//            rlim_t rlim_max;  /* Hard limit (ceiling for rlim_cur) */
// };
int main(int argc, char const *argv[])
{
	pid_t pid = atoi(argv[1]);
	struct rlimit new, old;

	if (prlimit(pid,RLIMIT_AS, NULL, &old) == 0) {
		printf("Virtual memory limit:\nold soft limt: %lld, old hard limit: %lld\n",(long long) old.rlim_cur, (long long)old.rlim_max);
	}

	if (prlimit(pid,RLIMIT_CORE, NULL, &old) == 0) {
		printf("Max size of core file:\nold soft limt: %lld, old hard limit: %lld\n",(long long) old.rlim_cur, (long long)old.rlim_max);
	}

	if (prlimit(pid,RLIMIT_CPU, NULL, &old) == 0) {
		printf("CPU time limit in seconds:\nold soft limt: %lld, old hard limit: %lld\n",(long long) old.rlim_cur, (long long)old.rlim_max);
	}

	if (prlimit(pid,RLIMIT_DATA, NULL, &old) == 0) {
		printf("max proces Data segment:\nold soft limt: %lld, old hard limit: %lld\n",(long long) old.rlim_cur, (long long)old.rlim_max);
	}
	return 0;
}