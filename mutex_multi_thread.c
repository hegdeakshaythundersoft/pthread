#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
unsigned long range,number,lock_var;
pthread_t tid_1,tid_2;
pthread_mutex_t mutex;
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



/*void *odd(void *p){
	lock_var=pthread_mutex_lock(&mutex);
	if(lock_var){
	printf("\nLock not acquired\n");
	pthread_exit(NULL);
	}
	do{
	if(number&1)
	printf("\nodd_val = %ld\n",number++);
	else
	pthread_mutex_unlock(&mutex);
	}while(number<=range);
	
}*/

void *even(void *p)
{
     lock_var = pthread_mutex_lock(&mutex);
     if(lock_var)
     {
	     printf("\n Lock not aquired");
         pthread_exit(NULL);
	 }
     
	 do
     {
         if(!(number&1))
         {
             printf("even_number %lu\n",number);
             number++;
         }
         else
         {
             pthread_mutex_unlock(&mutex);
         }
     } while (number <= range);
}


void *odd(void* q)
{
    lock_var = pthread_mutex_lock(&mutex);
	if(lock_var)
     {
	     printf("\n Lock not aquired");
         pthread_exit(NULL);
	 }

    do
    {
        if(number&1)
        {
            printf("odd_number %lu\n",number);
            number++;
        }
        else
        {
            pthread_mutex_unlock(&mutex);
        }
    } while (number <= range);
}
 
 
 
 /*
 
 
 
 akshay@akshay-ThinkPad-L570-W10DG:~/os$ gedit mutex_multi_thread.c&
[3] 18816
akshay@akshay-ThinkPad-L570-W10DG:~/os$ gcc mutex_multi_thread.c -l pthread
[3]-  Done                    gedit mutex_multi_thread.c
akshay@akshay-ThinkPad-L570-W10DG:~/os$ ./a.out

Enter the range
6
even_number 0
odd_number 1
even_number 2
odd_number 3
even_number 4
odd_number 5
even_number 6
akshay@akshay-ThinkPad-L570-W10DG:~/os$ 

 
 
 
 
 
 
 
 
 
 */
 
 
 
 
 
 
 
      
