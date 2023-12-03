#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.c>
#include <sys/types.c>
#include <unistd.h>
#include <pthread.h>

int main()
{
    pid_t t1, t2, t3;

    pthread_attr_t p1;
    pthread_attr_t p2;
    pthread_attr_t p3;

    pthread_attr_init
    pthread_attr_init
    pthread_attr_init

    pthread_create();
    pthread_create();
    pthread_create();

    pthread_join();
    pthread_join();
    pthread_join();

    void* f1(void*);
    void* f2(void*);
    void* f3(void*);

    return 0;
}

void* f1(void* p1)
{
    printf("Thread 1: Hello Milkyway Galaxy.\n");
    printf("Thread 1: My thread id is %lu\n", pthread_self());
    pthread_exit(0);
}

void* f2(void* p2)
{
    printf("Thread 2: Hello World.\n");
    printf("Thread 2: My thread id is %lu\n", pthread_self());
    pthread_exit(0);
}

void* f3(void* p3)
{
    printf("Thread 3: Hello India.\n");
    printf("Thread 3: My thread id is %lu\n", pthread_self());
    pthread_exit(0);
}