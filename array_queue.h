/*
	implement array queue with defined size.
*/

#define MAX_QUEUE_SIZE 100
//int i = 10; // not share between parent and child  
int currentqueueelement = 0;



int queue[MAX_QUEUE_SIZE];

// check for reentrant code
// check is queue is empty
int is_empty();

int add()
