/*
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

#define ARR_SIZE 20

void sort(int arr[], int arr_size) {

	return arr;
}

int get_median(int arr[], int arr_size) {

	return -1;
}


int main(int argc, char const *argv[])
{
	int arr[ARR_SIZE];
	sort(arr, ARR_SIZE);
	get_median(arr,ARR_SIZE);
	return 0;
}