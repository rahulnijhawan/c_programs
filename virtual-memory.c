#include <stdio.h>
#include <stdint.h>

// 14 bits of address space, last 2 bits of 14 bit is for segment number
#define SEG_MASK 0x3000 //1100 0000 0000 0000
#define SEG_SHIFT 0X000e //0000 
#define OFFSET_MASK 0x3FFF // 0011 1111 1111 1111



int main(int argc, char const *argv[])
{
	int16_t virtualAddress = 0x0001;
	int16_t segment, offset;

	segment = (virtualAddress & SEG_MASK) >> SEG_SHIFT;
	offset = (virtualAddress & OFFSET_MASK);
	printf("segment number %d\n, offset %d\n", segment, offset);
	return 0;
}