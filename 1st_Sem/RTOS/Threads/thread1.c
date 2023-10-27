/*Main program defines an array(Assume array size =5) and creates 
2 threads. 
One thread computes the sum of array elements.
 The second thread displays all odd numbers present in the array.
 (Pass the array as a parameter while creating the threads.) 
Aso Publish the process id and thread-id in every thread*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
#define LEN 5

int main()
{   int i;
  //  int arr1 = [12,34,44,5,98];
    pthread_t t1, t2;//creates 2 threads 't1' and 't2' to perform different tasks on arr1
    printf("Main: Process id is %d\n",getpid());//prints process id
    //printf("Main: Main thread id is %lu\n",pthread_self()); //ul - unsigned long integer, pthread_self() - function which returns thread ID of the calling thread 
    printf("\nMain thread: Here is the original array:\n");
        for(i=0; i<LEN; i++)
        {
            printf("%d/t",arr1[i]);
        }
        printf("\n");

    pthread_create(&t1,NULL,f1,arr1);//t1-creating new thread t1,NULL-default value,f1-function,arr1-argument to function f1
    pthread_create(&t2,NULL,f2,arr1);

    pthread_join(t1,NULL);//tells the main thread to wait for the thread with the ID t1 to finish its execution before proceeding further.
    //NULL argument is used for the second parameter, means that main thread doesn't need the return value of t1. To capture the return value of t1, you could pass a pointer to a variable instead of NULL.
 
   pthread_join(t2,NULL);
   printf("\nMain thread is exiting....\n");
}

void *f1(void *arr1)
    
    return 0;
}