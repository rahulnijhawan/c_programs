#include <stdio.h>

union {
	int num;
	char chr[2];
} NUM_or_CHAR;

int main(int argc, char const *argv[])
{
	NUM_or_CHAR.num = 0x4241;
	NUM_or_CHAR.chr[1] = 'f'; 
	printf("%s\n", NUM_or_CHAR.chr);
	
	return 0;
}
/*
	01000001
*/