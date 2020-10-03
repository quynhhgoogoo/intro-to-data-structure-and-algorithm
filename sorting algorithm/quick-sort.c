/*Find a correct index for a pivot element recursively*/
#include <stdio.h>
#include <stdlib.h>

/*swapping place of two intergers*/
void swap(int *x, int *y){
    int temp;

    temp = *x ;
    *x = *y;
    *y = temp;
}


/*Looking for correct place for pivot element*/
int partition(int A[], int l, int h){
    
    int pivot = A[l];

    /*i searches for elements smaller than or equal to pivot value
      j searches for elements bigger than pivot value*/
    int i=l, j=h;

    do{
        do{i++;} while(A[i]<=pivot);
        do{j--;} while(A[j]>pivot);

        if(i<j) swap(&A[i], &A[j]);
    } while (i<j);

    swap(&A[l], &A[j]);
    return j;
}


/*Sorting array by quicksort*/
void QuickSort(int A[], int l, int h){
    int j;

    if(l<h){
        j = partition(A,l,h);
        QuickSort(A,l,h);
        QuickSort(A,j+1,h);
    }
}

int main(){
    int A[] = {3,7,9,1,0,6,6,5,11,12}, n =10;
    int i;

    QuickSort(A,0,n-1);

    for (i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}