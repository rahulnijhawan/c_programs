#include <stdio.h>


enum bool{false, true};

int is_binary_digit(char c) {
	int zero_char_int_value = 48;
	int digit = (int) c - zero_char_int_value;

	if (digit == 0 || digit == 1) {
		return true;
	}
	return false;
}
char * add_sol1(char *bin_str1, char* bin_str2) {
	/*
		access one character from each from the end(left) and it using modula 2

		steps
			1-- get length of strings
			2-- decalare carry digit and initizialed to zero.
			3-- allocate string to contains result or use one of them????
			4-- start reading from last
			5-- add and take modula to 2
			6-- assing modula result to carry variable and divided(devide result(have to check)) 
				result to variable created at step 3.
			7-- reverse the string or use some other way to not reverse it(for example using one of them.) 
	*/


}

int main(int argc, char const *argv[])
{
	printf("%d\n", is_binary_digit('0'));
	printf("%d\n", is_binary_digit('2'));
	printf("%d\n", is_binary_digit('1'));
	return 0;
}