#include <stdio.h>
#include <math.h>

#define ELEMENT_IN(arrayname) (sizeof arrayname/sizeof *arrayname)

int main(int argc, char const *argv[])
{
	int a[] = {1, 3232, 3 , 4343,5};
	int tmp,i;
	int totalElm = ELEMENT_IN(a);
	printf("Before reverse\n");
	for (i = 0; i < totalElm; ++i)
	{
		printf("%5d,", a[i]);
	}

	for(i=0; i< (int)(floor(totalElm/2)); i++) {
		tmp = a[i];
		a[i] = a[totalElm-1-i];
		a[totalElm-1-i] = tmp;

	}
	printf("\nBefore reverse\n");
	for (i = 0; i < totalElm; ++i)
	{
		printf("%5d,", a[i]);
	}

	printf("\n");

	return 0;
}