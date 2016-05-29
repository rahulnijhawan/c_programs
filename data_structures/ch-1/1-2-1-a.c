/*
	-- run
		-- gcc file.c -o outfile -lm (why using lm when using ceil function.)

	The median of an array of numbers is the element m of the array such that half the remaining 
	numbers in the array are greater then or equal to m and half are less than or equal to m, 
	if the number of elements in the array is odd. if the number of elements is even, 
	the median is average of the two elements m1 and m2 such that half the remaining elements 
	are greater then or equal to m1 and m2 , and half the elements are less than or equal to 
	m1 and m2. Write a C function that acccepts an array of numbers and returns the median of 
	the numbers in the array.


	steps-1: get array and count of element in array.
	step-2: sort
	step-3: if count == 'odd': get one element at (count + 1)/2 else step-4
	step-4: get element at count/2 and (count+1)/2
	step-5: calc "mean/avg" of two elements get at step-4
	step-6: return val from step-3 or step-5
*/

#include <stdio.h>
#include <math.h>

#include "lib/sorts.h"

extern void bubble_sort_with_if_no_match(double [], int);

double get_median(double [], int);
int is_even(int);


#define ARR_SIZE 24

int main(int argc, char const *argv[])
{
	int i;
	double arr[] = {21,100,1,2,3,5,6,4,7,8,9,10,11,2,88,13,14,15,16,17,18,19,20,21};
	double median;
	median = get_median(arr, ARR_SIZE);
	for (i = 0; i < ARR_SIZE; ++i)
	{
		printf("%7.2lf", arr[i] );
	}
	printf("\n");
	
	printf("median %.2lf\n", median);
	// get_median(arr,ARR_SIZE);
	return 0;
}

double get_median(double arr[], int arr_size) {
	// odd number of integers
	int index1, index2;
	// bubble_sort_with_if_no_match(arr, arr_size);
	// insertion_sort(arr, arr_size);
	selection_sort(arr, arr_size);
	if (is_even(arr_size) == 0) {
		index1 = (arr_size/2) - 1;
		index2 = index1 + 1;

		return (arr[index1] + arr[index2])/2;
	} 

	index1 = ((arr_size+1)/2) -1;
	return arr[index1];
}

int is_even(int num) {
	return num % 2;
}
