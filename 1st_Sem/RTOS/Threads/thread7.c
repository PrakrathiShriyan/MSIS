


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 10

int matrix[MAX_SIZE][MAX_SIZE];
int size;

void *principalDiagonalSum(void *arg) {
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;

    for (int i = 0; i < size; i++) {
        *sum += matrix[i][i];
    }

    pthread_exit(sum);
}

void *nonPrincipalDiagonalSum(void *arg) {
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;

    for (int i = 0; i < size; i++) {
        *sum += matrix[i][size - i - 1];
    }

    pthread_exit(sum);
}

int main() {
    printf("Enter the size of the square matrix (maximum 10): ");
    scanf("%d", &size);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    pthread_t principalThread, nonPrincipalThread;
    int *principalSum, *nonPrincipalSum;

    pthread_create(&principalThread, NULL, principalDiagonalSum, NULL);
    pthread_create(&nonPrincipalThread, NULL, nonPrincipalDiagonalSum, NULL);

    pthread_join(principalThread, (void **)&principalSum);
    pthread_join(nonPrincipalThread, (void **)&nonPrincipalSum);

    printf("Principal Diagonal Sum: %d\n", *principalSum);
    printf("Non-Principal Diagonal Sum: %d\n", *nonPrincipalSum);

    // Writing to file
    FILE *file = fopen("matrix_sums.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "Principal Diagonal Sum: %d\n", *principalSum);
    fprintf(file, "Non-Principal Diagonal Sum: %d\n", *nonPrincipalSum);

    fclose(file);

    free(principalSum);
    free(nonPrincipalSum);

    return 0;
}
