#include <stdio.h>
/**
	------------- program structure-----------
		- text(code)
		- data segment (initialized variables)
		- bss(block started by symbols) (uninitialized variables)
		- heap
		- stack
	----------- end -----
	- ASLR: address space layout randomization.
*/


int main(int argc, char const *argv[])
{
	int data_seg_ends, brk_point;
	return 0;
}