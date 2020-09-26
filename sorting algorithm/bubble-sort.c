/*Compare consecutive pair of elements everytime*/
#include <stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp;

    temp = *x ;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n){

    int i, j;
    int flag = 0;       /*check if array is already sorted or not*/

    for (i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flag =1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int A[] = {3,7,9,1,0,6,6,5,11,12}, n =10;
    int i;

    BubbleSort(A,n);

    for (i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}