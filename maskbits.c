#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 8192
#define page_no(addr) (addr) >> 13

int main(int argc, char const *argv[])
{
	int page = page_no(atoi(argv[1]));

	printf("%d\n", page);
	return 0;
}