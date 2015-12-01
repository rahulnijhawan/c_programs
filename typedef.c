#include <stdio.h>
#include <stdlib.h>
#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#define ADD(a,b) (a+b)
#define LEFTSHIFT(a,numberTimes) (a<<numberTimes)
int length = 0;
char *s = NULL;
typedef struct /*person*/
{
	int id;
	char name[10];
} pers;

typedef struct Node Node;
struct Node {
    int data;
    Node *nextptr;
};

typedef int (*add)(int, int);

int funcAdd(int a, int b)
{
	return a+b;
}
int addf(add f,int a, int b){

	return f(a,b);
}
void AddToString(int ch);

int main()
{
	//typedef struct person pers;

	struct Node *startptr, *endptr, *curptr, *prevptr, errptr, *refptr;
	pers p;
	p.id = 10;
	printf("ADD(2,4) %d\n", ADD(2,4));
	printf("LEFTSHIFT %d\n", LEFTSHIFT(2,16));
	printf("%d\n", addf(funcAdd, 10,20));
	printf("%d\n", KERNEL_VERSION(2,6,10));
	typedef int I;
	typedef unsigned char BYTE;
	I i = 10;
	BYTE c = '1';

	AddToString(65);
	AddToString('\0');

	printf("%s\n", s);
	printf("%c\n", c);
}

int count = 0;

void numberOfCount()
{
	if (count >= 10) {
		return;
	}
	count++;
	//printf(count);
	numberOfCount();
}


void AddToString(int ch)
{
  //EnterCriticalSection(&someCriticalSection);
  // +1 for the character we're about to add
  // +1 for the null terminator
  char *newString = realloc(s, (length+1) * sizeof(char));

  if (newString) {
    if (ch == '\0' ) {
      AddToString('\\'); // escape prefix
    }
    newString[length++] = ch;
    newString[length] = '\0';
    s = newString;
  }
  //LeaveCriticalSection(&someCriticalSection);
}