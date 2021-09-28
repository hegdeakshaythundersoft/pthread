#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int base_val=50;
pthread_t tid;
typedef struct s{

	int m;
	char *c;

}structure;


void *structure_pass(void*);
void *structure_pass(void *p){
	structure *ptr=(structure*)p;
	printf("\nThe process ID is PID = %d\n",getpid());
	printf("\nThe current thread ID is TID = %ld\n",pthread_self());
	printf("\nThe struct value passed is m = %d\n",ptr->m);
	printf("\nThe struct string passed is *c = %s\n",ptr->c);
	printf("\nbase_val - struct_val = %d - %d  = %d\n",base_val,ptr->m,base_val-ptr->m);

}
int main(){	
	int data,ret_val;
	structure instance={6,"Passed structure"},*struct_var_address=&instance;
	ret_val=pthread_create(&tid,NULL,&structure_pass,struct_var_address);
	if(ret_val){
		printf("\nThread not created\n");
		return -1;
	}
	printf("\nThe process ID is PID = %d\n",getpid());
	printf("\nThe thread ID is TID = %ld\n",pthread_self());
	pthread_join(tid,NULL);
	

	return 0;
}
/*



akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit argument_pass.c&
[3] 20243
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc struct_pass.c -l pthread
[3]-  Done                    gedit argument_pass.c
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

The process ID is PID = 20280

The thread ID is TID = 140508969183040

The process ID is PID = 20280

The current thread ID is TID = 140508969178880

The struct value passed is m = 6

The struct string passed is *c = Passed structure

base_val - struct_val = 50 - 6  = 44
akshay@akshay-ThinkPad-L570-W10DG:~/os$ 




*/
