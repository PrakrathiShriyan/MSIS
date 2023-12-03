#define RAND_MAX 100
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#include <stdlib.h>

int matrix[3][4];

void *Thread(void *);

int main()
{
    int count;

    pthread_t t1, t2, t3, t4;
    int thread_results[4] = {0, 1, 2, 3};
    printf("This Code is not working as Intended...!!");
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());

    count = sizeof(matrix) / sizeof(matrix[0]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("[");
        for (int j = 0; j < 4; j++)
        {
            printf(" %d\t", matrix[i][j]);
        }
        printf("]\n");
    }

    pthread_create(&t1, NULL, Thread, &thread_results[0]);
    pthread_create(&t2, NULL, Thread, &thread_results[1]);
    pthread_create(&t3, NULL, Thread, &thread_results[2]);
    pthread_create(&t4, NULL, Thread, &thread_results[3]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    printf("\n back to Main\n");
    int matrix_sum = 0;
    for (int i = 0; i < 4; i++)
    {
        matrix_sum += thread_results[i];
    }
    printf("\nMain thread computed %d + %d + %d + %d = %d\n", thread_results[0], thread_results[1], thread_results[2], thread_results[3], matrix_sum);
    printf("\nMain thread is exiting...\n");
}
void *Thread(void *in)
{
    int colum = *((int *)in);
    int *result = ((int *)in);
    int i;
    printf("Thread1: Process id is %d\n", getpid());
    printf("Thread1: Thread id is %lu\n", pthread_self());

    printf("Thread %d computing sum\n", colum + 1);
    *result = 0;
    for (i = 0; i < 3; i++)
    {
        *result += matrix[i][colum];
    }
    printf("Thread %d computed sum = %d\n", colum + 1, *result);
    pthread_exit(NULL);
} 