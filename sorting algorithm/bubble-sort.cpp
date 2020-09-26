#include <iostream>

using namespace std;

template <class T>
void Print(T &vec, int n, string s){
    cout << s << ": [" <<flush;
    for(int i=0; i<n;i++){
        cout << vec[i] << flush;
        if(i<n-1){
            cout<< "," <<flush;
        }
    }
    cout<< "]" <<endl;
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n){
    int i,j, flag =0;

    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
         if(flag==0){
                break;
        }
    }
}

int main(){
    int A[] = {3,7,9,1,0,6,6,5,11,12};
    int n = sizeof(A)/sizeof(A[0]), i;

    BubbleSort(A,n);
    Print(A, n, "Sorted A: ");
    
    return 0;
}