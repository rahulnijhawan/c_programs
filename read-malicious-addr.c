#include <stdio.h>


/*point to malicious location not in this process may be memory first address let see*/
char *cptr;
cptr = 0;

int main()
{

	while(gets(cptr))
		printf("%s\n",*cptr);
	return 0;
}

