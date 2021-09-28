#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
//int i;
void *my_thread(void*);
void fun(void);
void fun(){

	printf("\nfunction called from main\n");
	return;

}
void *my_thread(void *ptr){
	
	//pthread_detach(pthread_self());
	printf("\nthe user thread ID is = %ld\n",pthread_self());
	//sleep(2);
	int i;
	int *n=(int*)ptr,data=*n;
	for(i=0;i<data;i++)
	printf("\ni=%d\n",i);
	printf("\nInside user thread\n");
	
	return (void*)20;
	
	//pthread_exit(NULL);

}
int main(){


	pthread_t tid;
	int ret,var;
	void *rval;
	printf("\nenter the limit\n");
	scanf("%d",&var);
	ret=pthread_create(&tid,NULL,&my_thread,&var);/*NULL--->&var last arg*/
	if(ret){
	
		printf("\nthread is not created\n");
		return -1;
	}
	
	//pthread_create(&tid,NULL,my_thread,NULL);
	/*
	int pthread_create (pthread_t *thread,const pthread_attr_t *attr,void *(*start_routine) (void *),void *arg);
	*/
	//sleep(2);
	printf("\nIn the main function\n");
	fun();/*in the same thread with the main*/
	pthread_join(tid,rval);
	//printf("\nThe return address from user_thread function is = %d\n",rval);
	printf("\nBack to main function\n");
	printf("\nPID = %d\n",getpid());
	//pthread_exit(NULL);/*to prevent the detached threads parallel even after completion of main*/
	
	return 0;
	}
	
	
	/*
	
	
	
	************************** detached user thread *********************************
	
	
	
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit my_thread.c 
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc my_thread.c -l pthread
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

enter the limit
5

In the main function

function called from main

Back to main function

the user thread ID is = 139829198337792

i=0

i=1

i=2

i=3

i=4

Inside user thread
akshay@akshay-ThinkPad-L570-W10DG:~/os$ 

	
	
	
	
	
	
	************************** un-detached user thread *********************************
	
	
	
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit my_thread.c 
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc my_thread.c -l pthread
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

enter the limit
6

In the main function

function called from main

the user thread ID is = 140400034699008

i=0

i=1

i=2

i=3

i=4

i=5

Inside user thread

Back to main function

	
	
	
	
	
	
	
	
	
	
********************** un-detached and printing process - ID ******************************************
	
	
	
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit my_thread.c 
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc my_thread.c -l pthread
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

enter the limit
4

In the main function

function called from main

the user thread ID is = 139740116576000

i=0

i=1

i=2

i=3

Inside user thread

Back to main function

PID = 16590

	
	
	
	
**************************************** not using exit for main thread ********************************




akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit my_thread.c 
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc my_thread.c -l pthread
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

enter the limit
7

In the main function

the user thread ID is = 139663816251136

i=0

i=1

i=2

i=3

i=4

i=5

i=6

Inside user thread

function called from main

Back to main function

PID = 16628

	
	
	
	
	
	
	
	
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
