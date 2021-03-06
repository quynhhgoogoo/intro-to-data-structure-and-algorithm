#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int l, int mid, int h){
    int i = l, j = mid + 1, k = l;
    int B[100];

    /* Merging two sorted lists from array A into B */
    while (i <= mid && j <= h){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        }
        else {
            B[k++] = A[j++];
        }
    }

    /* Copying the rest of elements two B if one of the sorted list has no element left to compare */
    for (; i <= mid; i++){
        B[k++] = A[i];
    }
    for (; j <= h; j++){
        B[k++] = A[j];
    }

    /* Transfering elements from B to A again */
    for (i = l; i <= h; i++){
        A[i] = B[i];
    }
}


void IterativeMergeSort (int A[], int n){
    /* p: number of passes
       l: low, h: height, mid: middle */
    int p, l, h, mid, i;

    /* Iteratively sort and merge array by dividing elements */
    for (p = 2; p <= n; p = p*2){
        for (i = 0; i + p -1 < n; i = i + p){
            l = i;
            h = i + p -1;
            mid = (l + h)/2;
            Merge(A, l, mid, h);
        }

        /* if the number of elements is odd: cannot divide all element into subgroups */
        if (n-i > p/2){
            l = i;
            h = i + p - 1;
            mid = (l + h)/2;
            Merge(A, l, mid, n - 1);
        }
    }

    /* if the number of elements is odd: one element has been left */
    if (p/2 < n){
        Merge(A, 0, p/2 - 1, n - 1);
    }
}


void RMergeSort(int A[], int l, int h){
    int mid;
    /* if there is more than one element inside array */
    if (l < h){
        mid = (l + h)/2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

void Print(int A[], int n){
    for(int i = 0; i < n; i++) 
        printf("%d ",A[i]); 
    printf("\n");
}


int main() {
    int A[] = {11,5,14,2,6,3,1};
    int n = 7; 
    
    printf("Iterative merge sort: ");
    IterativeMergeSort(A, n); 
    Print(A, n);

    printf("Recursive merge sort: ");
    RMergeSort(A, 0, n-1);
    Print(A,n);
     
    return 0;
}
