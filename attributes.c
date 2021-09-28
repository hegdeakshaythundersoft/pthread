#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *my_thread(void *p){

	printf("\nEmpty \n");
	//pthread_exit(NULL);
}

int main(){

int ret,s,detach_state;
pthread_t tid;  	// thread id
size_t stacksize;	// stacksize

pthread_attr_t attr;	// pthread attribute instance -> attr

pthread_attr_init(&attr); // initialising attribute -> attrs

pthread_attr_getstacksize(&attr,&stacksize); // get stacksize 
printf("\nCurrent stack size %ld\n",stacksize); // print stack size

pthread_attr_setstacksize(&attr,10000000);   // set new stack size 	

pthread_attr_getstacksize(&attr,&stacksize); // get stacksize  after setting a new one
printf("\nNew stack size %ld\n",stacksize);	// print stack size

s = pthread_attr_setdetachstate(&attr,1); // 1=detach, 0=join

s = pthread_attr_getdetachstate(&attr, &detach_state); // get detachstate

ret = pthread_create(&tid,&attr,&my_thread,NULL); // create a thread
printf("\nBack to main function\n");
pthread_exit(NULL);		// exit thread

return 0;
}

/*





akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit attributes.c
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc attributes.c -l pthread
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

Current stack size 8388608

New stack size 10000000

Back to main function

Empty 









*/
