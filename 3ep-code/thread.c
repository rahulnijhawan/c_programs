#include <pthread.h>// pthred_create

#include <unistd.h>// sleep
#include <stdio.h>// printf


#include "error.h"// err




volatile int i = 0;

static void * f1(void *arg)
{
	while(i==0){

	}
	printf("i value changed\n");
}

static void * f2(void *arg)
{
	sleep(2);
	i=1;
	printf("i value changed to %d\n", i);

}

int main(int argc, char const *argv[])
{
	pthread_t t1, t2;
	int rvt1, rvt2;

	rvt1 = pthread_create(&t1, NULL, f1, NULL); 
	if (rvt1 < 0) {
		err("thread 1 failed");
	}

	rvt2 = pthread_create(&t2, NULL, f2, NULL);
	if (rvt2 < 0) {
		err("thread 2 failed");
	}	

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}