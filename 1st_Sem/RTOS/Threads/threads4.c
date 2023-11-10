/*Main computes matrix sum from the partial results
given by the threads. Each thread computes a column sum*/

#include <stdio.h>
#include <pthread.h>
#define ROW 3
#define COL 3

void* f1(void*);
void* f2(void*);
void* f3(void*);
pthread_t t1, t2, t3;

//Global defination
int mat[3][3] = {{10,11,12},{2,2,2},{3,3,3}};
int sum3=0, sum2=0, sum1=0, total=0;

int main(){
    int i, j;
    printf("Here's the given matrix:\n");

    for(i=0;j<ROW;j++)
    {
        for(j=0;j<COL;j++)
        printf("%d\t",mat[i][j]);
        printf("\n");
    }

    printf("\n");

    pthread_create(&t1,NULL,f1,NULL);
    pthread_create(&t2,NULL,f2,NULL);
    pthread_create(&t3,NULL,f3,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    printf("\nAll threads have finished executing...\n\n");
    total=sum1+sum2+sum3;
    printf("Total sum= %d\n\n",total);
    return 0;
}

void* f1(void* p1)
{
    int i, j;
    
    for(i=0, j=0; i<ROW; i++)
    sum1 = sum1+mat[i][j];
    printf("Sum of COL1=%d\n",sum1);
    pthread_exit(0);
}

void* f2(void* p1)
{
    int i, j;
    
    for(i=0, j=1; i<ROW; i++)
    sum2 = sum2+mat[i][j];
    printf("Sum of COL2=%d\n",sum2);
    pthread_exit(0);
}

void* f3(void* p1)
{
    int i, j;
    
    for(i=0, j=2; i<ROW; i++)
    sum3 = sum3+mat[i][j];
    printf("Sum of COL3=%d\n",sum3);
    pthread_exit(0);
}