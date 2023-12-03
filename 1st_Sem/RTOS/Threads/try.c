#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 10
#define matrix [MAX][MAX]

int main()
{  
    printf("Enter the size (MAX 10):");
    scanf("%d",size);

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
        {
            scanf("%d",&arr[size][size])
            
        }

    pthread_t t1;
    pthread_t t2;

    pthread_attr_t arr1;
    pthread_attr_t arr2;

    pthread_attr_init(&arr1);
    pthread_attr_init(&arr2);

    pthread_create(&t1, NULL, f1, &arr1);
    pthread_create(&t2, NULL, f2, &arr2);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    void* f1(void*);//function to find sum of principal diagonal elements
    void* f2(void*);//function to find sum of diagonal elements

    FILE *fp1;
    fp1 = fopen("matrix.txt","w");
    fprintf("%d",principal_diagonalsum);
    fprintf("%d",digonalsum);
    fclose(fp1);

}

void* f1(void* arr)
{
    for(int i=0; i<size; i++)
    {
        sum+=[i][i];
    }
}

void* f2(void* arr)
{
    for(int i=; i<size; i++)
    {
        sum+=[i][i];
    }
}