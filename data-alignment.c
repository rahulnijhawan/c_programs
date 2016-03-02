/*
	data alignment by 32 bits or 64 bits for fast accessing the data in memory.

	computing padding
	-- bitwise AND and NOT(~)
		--  padding = align - (offset & (align - 1)) = (-offset) & (align - 1)
			new offset = (offset + align - 1) & ~(align - 1)
	--  padding = (align - (offset mod align)) mod align
		new offset = offset + padding = offset + (align - (offset mod align)) mod align
*/

#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_IN(arrayname) (sizeof arrayname/ sizeof *arrayname)
#define offsetof(st,m) ((size_t)(&((st *)0)->m))

int main(int argc, char const *argv[])
{
	//extern int ea[];
	//int ia[];
	long int padding= -(0x59d)&(7);
	printf("%ld\n", padding );
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


	#pragma pack(push)
	#pragma pack(1)
	struct dt3
	{
		char c;
		short s;
		int i;
		char c1;
	};
	#pragma pack(pop)

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
	printf("sizeof(int) %zu\n", sizeof(int));	
	printf("data size of struct dt %zu\n", sizeof(struct dt) );
	printf("array total size: %zu and array element size: %zu\n", sizeof i, sizeof *i );
	printf("malloc char sizeof: %zu, static char array sizeof %zu\n", sizeof cp, sizeof c );
	printf("sizeof (struct dt1) %zu\n", sizeof (struct dt1) );
	printf("sizeof (struct dt2) %zu\n", sizeof (struct dt2) );
	printf("sizeof (struct dt3) %zu, after reordering dt3(dt4) size is: %zu\n", sizeof (struct dt3), sizeof (struct dt4));
	printf("offsetof %zu\n",offsetof(struct dt4,c) );
	struct dt3 *dtp = ((struct dt3 *)0);
	//printf("%d\n", *dtp );
	printf("offsetof %zu\n", (size_t) &(dtp->c1) );
	/*  error: invalid application of ‘sizeof’ to incomplete type ‘int[]’
		printf("%zu\n", sizeof ea );
	*/
	/*  error: array size missing in ‘ia’
		printf("%zu\n", sizeof ia );
	*/ 
	return 0;
}