#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/* Searching for the largest element inside array */
int findMax(int A[], int n){
    int max = INT_MIN;
    int i;

    for (i = 0; i < n; i ++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}


void CountSort(int A[], int n){
    int i, j, max, *C;
    max = findMax(A, n);

    /* Initialize an array that contains the occurence of elements inside A 
       0 : Element does not exist in A */
    C = (int *)malloc(sizeof(int) * (max + 1));
    for( i = 0; i < max + 1; i++){
        C[i] = 0;
    }

    /* Insert the number of element occurences from A to C */
    for (i = 0; i < n; i++){
        C[A[i]]++;
    }

    /* Transfering elements from C back to A */
    i = 0;
    j = 0;
    while (j < max + 1){
        /* if element is available in A */
        if (C[j] > 0){
            A[i++] = j;
            C[j]--;
        }
        else {
            j++;
        }
    }
}


/* Print out array's content */
void Print(int A[], int n){
    for(int i = 0; i < n; i++) 
        printf("%d ",A[i]); 
    printf("\n");
}


int main() {
    int A[] = {11,5,14,2,6,3,1};
    int n = 7; 
    
    printf("Count sort: ");
    CountSort(A, n);
    Print(A, n);

    return 0;
}
