#include <stdio.h>
#include <string.h> // strlen, memmove, memset

#define BINARY_STRING_LEN 4


enum bool{false, true};

int is_binary_digit(char c) {
	int zero_char_int_value = '0';
	int digit = (int) c - zero_char_int_value;
	
	if (digit == 0 || digit == 1) {
		return true;
	}
	return false;
}

int is_binary_string(const char *bin_str) {
	
	// find search methond other than linear search.?????
	// string end with null charachter
	while (*bin_str != '\0') {
		if (is_binary_digit(*bin_str) == false) {
			return false;
		} 
		bin_str++;
	}
	return true;
}

void * prepend_zeros(char *bin_str) {

	/*
		moving chars to end and then prepend zeros is expensive? or find other options???
		-- memmove
	*/
	char temp[BINARY_STRING_LEN];
	int len = strlen(bin_str);
	int diff = BINARY_STRING_LEN - len - 1;
	printf("len %d, diff %d\n", len, diff);
	if (diff > 0) {
		memmove((bin_str + diff), bin_str, len);
		memset(bin_str, (int) '0', diff );
	}

	return bin_str;
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
	
		validation
			-- must be of equal length or make it equal by prepening zeros.
			-- test for binary string.
	*/
	int i = 0;
	int carry = 0;
	int str1_len, str2_len;
 	// check for binary string????
	prepend_zeros(bin_str1);
	prepend_zeros(bin_str2);
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	for(i = BINARY_STRING_LEN-2; i >=0; i--) {
		//printf("%c, %c\n", *(bin_str1 + i), *(bin_str2 + i));
		num1 = *(bin_str1 + i) - '0';
		num2 = *(bin_str2 + i) - '0';
		sum = num1 + num2 + carry;
		printf("num1 %d, num2 %d, carry %d, sum((num1 + num2 + carry) / 2) %d\n",num1, num2, carry, sum);  
		
		carry = sum / 2;
		bin_str1[i] = (sum % 2) + '0';

	}	
	return bin_str1;
}

int main(int argc, char const *argv[])
{

	printf("is_binary_digit %d\n", is_binary_digit('0'));
	printf("is_binary_digit %d\n", is_binary_digit('2'));
	//printf("is_binary_string %d\n", is_binary_string(argv[1]));

	char bin_str1[BINARY_STRING_LEN] = argv[1]; //"1111000000000000000\0";
	char bin_str2[BINARY_STRING_LEN] = argv[2]; //"11111111\0";

	//printf("%s\n", (char *) prepend_zeros(bin_str1));
	printf("%s\n", add_sol1(bin_str1, bin_str2));
	return 0;
}