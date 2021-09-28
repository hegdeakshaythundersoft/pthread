#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int base_val=50;
pthread_t tid;
void *subtract_data(void*);
void *subtract_data(void *p){
	int *ptr=(int*)p;
	int data_val=*ptr;
	printf("\nThe process ID is PID = %d\n",getpid());
	printf("\nThe current thread ID is TID = %ld\n",pthread_self());
	printf("\nThe data value passed is = %d\n",data_val);
	printf("\nbase_val - data_val = %d - %d  = %d\n",base_val,data_val,base_val-data_val);

}
int main(){	
	int data,ret_val;
	printf("\nEnter the data to be passed and subtracted\n");
	scanf("%d",&data);/*ex: 10------ 50-10=40*/
	ret_val=pthread_create(&tid,NULL,&subtract_data,&data);
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
[3] 17680
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc argument_pass.c -l pthread
[3]-  Done                    gedit argument_pass.c
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out 

Enter the data to be passed and subtracted
10

The process ID is PID = 17691

The current thread ID is TID = 139857316316928

The data value passed is = 10

base_val - data_val = 50 - 10  = 40

The process ID is PID = 17691

The thread ID is TID = 139857316321088
akshay@akshay-ThinkPad-L570-W10DG:~/os$ 














*/
