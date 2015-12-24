#include <stdio.h>

#include <netdb.h>

#define __LINUX 
#ifdef __LINUX
	#define NEW_LINE "\n"
#else
	#define NEW_LINE "\r\n"
#endif

int main(int argc, char const *argv[])
{
	struct protoent *prot;
	int i = 0;
	printf("%s%15s%18s%s","protocal Name", "protocol Alias","Protocol Number", NEW_LINE);

	while(prot=getprotoent()) {
		printf("%10s%20s%d%s", prot->p_name,"",prot->p_proto, NEW_LINE);
		for(i = 0;prot->p_aliases[i];i++) {
			printf("%s%s", prot->p_aliases[i],NEW_LINE);
		}
	}
	return 0;
}