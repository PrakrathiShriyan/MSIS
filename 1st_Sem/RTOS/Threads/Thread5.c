#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void* f1(void*);
void* f2(void*);
void* f3(void*);


int main()
{
    pthread_t t1, t2, t3;

    pthread_attr_t p1;
    pthread_attr_t p2;
    pthread_attr_t p3;

    pthread_attr_init(&p1);
    pthread_attr_init(&p2);
    pthread_attr_init(&p3);

    pthread_create(&t1, NULL, f1, &p1);
    pthread_create(&t2, NULL, f2, &p2);
    pthread_create(&t3, NULL, f3, &p3);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    return 0;
}

void* f1(void* p1)
{
    wait(NULL);
    printf("Thread 1: Hello Milkyway Galaxy.\n");
    printf("Thread 1: My thread id is %lu\n", pthread_self());
    pthread_exit(0);
}

void* f2(void* p2)
{
    wait(NULL);
    printf("Thread 2: Hello World.\n");
    printf("Thread 2: My thread id is %lu\n", pthread_self());
    pthread_exit(0);
}

void* f3(void* p3)
{
    wait(NULL);
    printf("Thread 3: Hello India.\n");
    printf("Thread 3: My thread id is %lu\n", pthread_self());
    pthread_exit(0);
}