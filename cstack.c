#include <stdio.h>
#include <stdlib.h>

#define STACK_BOTTOM 0
#define STACK_MAX 50

int stack[STACK_MAX];
int stackTop = 0; // what if using 0

void push(int);
int pop();

int main()
{
	pop();
	push(10);
	push(20);
	for (int i = stackTop; i >= 0 ;i--) {
		printf("%d\n", pop());
	}
	
}


void push(int v)
{
	if (stackTop > STACK_MAX) {
		exit(1);
	}

	stack[stackTop++] = v;
}

int pop()
{
	if (stackTop < STACK_BOTTOM) {
		exit(1);
	}
	
	return stack[stackTop--];
}