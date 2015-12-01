/*
	data alignment by 32 bits or 64 bits for fast accessing the data in memory. 
*/

#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_IN(arrayname) (sizeof arrayname/ sizeof *arrayname)
#define offsetof(st,m) ((size_t)(&((st *)0)->m))

int main(int argc, char const *argv[])
{
	//extern int ea[];
	//int ia[];
	struct dt
	{
		char c;
		int a[];
	};

	struct dt1
	{
		char c[5];
		int a;
	};

	struct dt2 
	{
		short i;
		char c[3];
	};

	struct dt3
	{
		char c;
		short s;
		int i;
		char c1;
	};

	// after reordering dt3
	struct dt4
	{
		char c;
		char c1;
		short s;
		int i;
	};

	struct dt4 ds;

	int i[10];
	char *cp = (char *) malloc(10 * sizeof(char));
	char c[10];
	printf("data size of struct dt %zu\n", sizeof(struct dt) );
	printf("array total size: %zu and array element size: %zu\n", sizeof i, sizeof *i );
	printf("malloc char sizeof: %zu, static char array sizeof %zu\n", sizeof cp, sizeof c );
	printf("sizeof (struct dt1) %zu\n", sizeof (struct dt1) );
	printf("sizeof (struct dt2) %zu\n", sizeof (struct dt2) );
	printf("sizeof (struct dt3) %zu, after reordering dt3 size is: %zu\n", sizeof (struct dt3), sizeof (struct dt4));
	printf("offsetof %zu\n",offsetof(struct dt4,c) );
	struct dt3 *dtp = ((struct dt3 *)0);
	printf("%u\n", *dtp );
	printf("offsetof %zu\n", (size_t) &(dtp->c1) );
	/*  error: invalid application of ‘sizeof’ to incomplete type ‘int[]’
		printf("%zu\n", sizeof ea );
	*/
	/*  error: array size missing in ‘ia’
		printf("%zu\n", sizeof ia );
	*/ 
	return 0;
}