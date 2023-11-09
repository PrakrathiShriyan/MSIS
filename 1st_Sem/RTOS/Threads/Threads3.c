#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* calls(void* ptr)
{
    printf("In function thread id = %lu\n", pthread_self());
    pthread_exit(NULL); //To allow other threads to continue execution, the main thread should terminate by calling pthread_exit()
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, calls, NULL);
    printf("In main thread id = %lu\n", pthread_self());
    pthread_join(thread, NULL);
    return 0;
}