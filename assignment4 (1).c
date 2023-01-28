#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef NUM_THREADS
#define NUM_THREADS 2
#endif
void *threadFunction(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("Hi, I am thread %ld, pthread ID - %lu\n", tid,pthread_self());
	for(int n = 1; n <= 30000; n+=1){
		if(n % 2000 == 0){
			printf("Thread %ld is on step %i:\nid:%lu\n",tid,n, pthread_self());
		}
	} 
	pthread_exit(NULL);
	
}
int main(int argc, char const *argv[]){
	printf("Jake Peters\n");
	// creating thread ID
	pthread_t threads[NUM_THREADS];
	int ret_1;
	long t;
	//create threads
	for(t = 1; t <= NUM_THREADS;t++){
	ret_1 = pthread_create(&threads[t],NULL,threadFunction,(void *)t);
	if(ret_1){
		printf("Error; return code is %d\n",ret_1);
		exit(EXIT_FAILURE);
	}
}

	pthread_exit(NULL);
	
	}
	
	
