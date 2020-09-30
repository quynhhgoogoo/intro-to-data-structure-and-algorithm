/*Divide array into two lists: sorted and unsorted*/
#include <stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp;

    temp = *x ;
    *x = *y;
    *y = temp;
}

/*Input: Array and number of elements
  Output: Void insertion sort*/
void InsertionSort(int A[], int n){
    int i, j, x;
    
    for(i=1; i<n; i++){
        j = i-1;
        x = A[i];

        /*Shifting elements*/
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main(){
    int A[] = {3,7,9,1,0,6,6,5,11,12}, n =10;
    int i;

    InsertionSort(A,n);

    for (i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}