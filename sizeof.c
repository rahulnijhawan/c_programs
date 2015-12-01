#include <stdio.h>


int main(int argc, char const *argv[])
{
	struct s
	{
		char c;
		int a;
	};

	printf("padding struct to make it size to %zu", sizeof (struct s));
	return 0;
}