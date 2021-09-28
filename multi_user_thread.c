#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
unsigned long range,number;
pthread_t tid_1,tid_2;
void *even(void*);
void *odd(void*);

int main(){
	printf("\nEnter the range\n");
	scanf("%lu",&range);
	
	
	pthread_create(&tid_1,NULL,&even,NULL);
	pthread_create(&tid_2,NULL,&odd,NULL);
	
	pthread_join(tid_1,NULL);
	pthread_join(tid_2,NULL);
	
	return 0;
}



void *odd(void *p){
	do{
	if(number&1)
	printf("\nodd_val = %ld\n",number++);
	}while(number<=range);
}

void *even(void *q){
	do{
	if(!(number&1))
	printf("\neven_val = %ld\n",number++);
	}while(number<=range);
}

/*

akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit mutex_multi_thread.c&
[3] 18325
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc mutex_multi_thread.c -l pthread
[3]-  Done                    gedit mutex_multi_thread.c
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

Enter the range
10

even_val = 0

odd_val = 1

odd_val = 3

even_val = 2

odd_val = 5

even_val = 4

even_val = 6

even_val = 8

odd_val = 7

odd_val = 9

even_val = 10













*/

