#include <stdio.h>


#define WHERESTR  "[file %s, line %d]: "
#define WHEREARG  __FILE__, __LINE__
#define DEBUGPRINT2(...)       fprintf(stderr, __VA_ARGS__)
#define DEBUGPRINT(_fmt, ...)  DEBUGPRINT2(WHERESTR _fmt, WHEREARG, __VA_ARGS__)

int main(int argc, char const *argv[])
{
	DEBUGPRINT("hello %d\n",10);
	#line 314 "pi.c"
	printf("line=%d file=%s\n", __LINE__, __FILE__);
	return 0;
}