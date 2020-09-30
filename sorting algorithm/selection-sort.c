/*P1: keep track on position
  P2: tranversing through array
  P3: keep track on the minimum value*/

#include <stdio.h>
#include<stdlib.h>

/*Swapping two elements*/
void swap(int *x, int *y){
    int temp;

    temp = *x ;
    *x = *y;
    *y = temp;
}

/*Sorting elements inside array using Selection Sort*/
void SelectionSort(int A[], int n){
    int i, j, k;

    for(i=0; i<n; i++){
        /*Tranversing through array to find the next min value*/
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
            swap(&A[i], &A[k]);
        }
    }
}

int main(){
    int A[] = {3,7,9,1,0,6,6,5,11,12}, n =10;
    int i;

    SelectionSort(A,n);

    for (i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}