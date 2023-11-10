#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define USE_MUTEX 1
#if (USE_MUTEX == 1)
pthread_mutex_t file_mutex;
#endif
void *Thread_1(void *);
void *Thread_2(void *);

FILE *fp = NULL;

int main()
{

    pthread_t t1, t2;
    printf("Main: Process id is %d\n", getpid());
    printf("Main: Main thread id is %lu\n", pthread_self());
#if (USE_MUTEX == 1)
    if (pthread_mutex_init(&file_mutex, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }
#endif
    pthread_create(&t1, NULL, Thread_1, NULL);
    pthread_create(&t2, NULL, Thread_2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nMain thread is exiting...\n");
}
void *Thread_1(void *in)
{
    FILE *fp_new = NULL;
    printf("T1\n");
#if (USE_MUTEX == 1)
    pthread_mutex_lock(&file_mutex);
#endif
    printf("T1 m\n");
    fp = fopen("sample.txt", "r");
    fp_new = fopen("result.txt", "w");
    char ch = getc(fp);
    while (ch != EOF)
    {
        putc(ch, fp_new);
        ch = getc(fp);
    }
    printf("Copy complete\n");
    fclose(fp);
    fclose(fp_new);
#if (USE_MUTEX == 1)
    pthread_mutex_unlock(&file_mutex);
#endif
    pthread_exit(NULL);
}

void *Thread_2(void *in)
{
    FILE *fp_new = NULL;
    sleep(2);
    printf("T2\n");
#if (USE_MUTEX == 1)
    pthread_mutex_lock(&file_mutex);
#endif
    printf("T2 m\n");
    fp_new = fopen("result.txt", "a+");
    char input[10] = "";
    int count = 0;
    scanf("%s", input);
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        int index = 0;
        while (input[index] != '\0')
        {
            putc(input[index], fp_new);
            index++;
        }
    }

    fclose(fp_new);
#if (USE_MUTEX == 1)
    pthread_mutex_unlock(&file_mutex);
#endif
    pthread_exit(NULL);
}