/*Sorting max heap*/
#include <stdio.h>

void Insert(int A[], int n){
    int temp;
    temp = A[n];
    
    /*Comparing current value to its parent's element*/
    while(n>1 && temp>A[n/2]){
        A[n] = A[n/2];
        n = n/2;
    }
    A[n] = temp;
}

int Delete(int A[], int n){
    int i, j, x, temp, val;
    x = A[n];
    
    /*Swapping first element and last element*/
    val = A[1];
    A[1] = A[n];
    A[n] = val;

    i = 1;
    j = i*2;
    while(j <= n-1){
        /*Comparing child nodes*/
        if(j<n-1 && A[j+1] > A[j]){
            j = j+1;
        }
        /*Swapping child node to root node*/
        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }
    return val;
}

int main(){
    int H[] = {0,14,15,5,20,30,8,40};
    int i;

    /*Rearrange elements inside heap*/
    for(i=2;i<=7;i++){
        Insert(H,i);
    }    
    for(i=1; i<=7; i++){
        Delete(H,i);
    }

    for(i=1;i<=7;i++){
        printf("%d ",H[i]);
    }
    printf("\n");
    return 0;
}