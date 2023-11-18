#include<stdio.h>
#include<stdlib.h>
#include"Bubble.c"
#include"Insertion.c"
#include"Selection.c"
#include"print.c"

int main() {
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    // Sorting the array using bubble sort
    //Bubble(A, n);
    //Insertion(A, n);
    Selection(A, n);
    //Insertion(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}