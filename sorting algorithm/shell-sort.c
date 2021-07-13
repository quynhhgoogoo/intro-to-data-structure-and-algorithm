#include <stdio.h>
#include <stdlib.h>


void ShellSort(int A[], int n){
    int gap, i, j, temp;

    for (gap = n/2; gap >=1; gap /= 2){
        for (i = gap; i < n; i++){
            temp = A[i];
            j = i - gap;

            /* Swapping elements */
            while (j >= 0 && A[j] > temp){
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}


/* Print out the content of an array */
void Print(int A[], int n){
    for(int i = 0; i < n; i++) 
        printf("%d ",A[i]); 
    printf("\n");
}


int main() {
    int A[] = {11,5,14,2,6,3,1};
    int n = 7; 
    
    Print(A, n);
    printf("Shell sort: ");
    ShellSort(A, n); 
    Print(A, n);
     
    return 0;
}
