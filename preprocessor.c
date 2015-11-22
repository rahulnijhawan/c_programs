#include <stdio.h>
/*
	? You cannot combine a macro argument with additional text and stringify it all together. 
	You can however write a series of adjacent string constants and stringified arguments: 
	the C compiler will then combine all the adjacent string constants into one long string.

// token stringification- # operator known as the "Stringification Operator"
*/
#define str(s) #s
#define xstr(s) str(s)
#define FOO 4


/*
	// ## operator know as "token pasting operator"
	?#define DECLARE_STRUCT_TYPE(name) typedef struct name##_s name##_t
	?DECLARE_STRUCT_TYPE(g_object); // Outputs: typedef struct g_object_s g_object_t;
*/
#ifndef FOO
	/*
		The #error directive outputs a message through the error stream.
	*/
	#error "not defined"
#endif 
int main(int argc, char const *argv[])
{
	printf("%s\n",str(p="foo=\n") );
	printf("%s...\n",str(\t));
	printf("%s\n", str(FOO) );
	printf("%s\n", xstr(FOO) );
	return 0;
}