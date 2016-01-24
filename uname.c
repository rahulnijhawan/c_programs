/*

	show name and information about current kernel

*/



#include <stdio.h>

#include <sys/utsname.h> // UTS stand for Unix Timesharing system

#include "error.h"

#define LINUX_VERSION_CODE 199945
#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
int main(int argc, char const *argv[])

{
	struct utsname utsn;

	if (uname(&utsn) == -1) {
		err("uname:");
	}

	printf("%s %s\n",utsn.sysname, utsn.nodename );
	printf("%d\n", KERNEL_VERSION(3,13,0));
	return 0;
}