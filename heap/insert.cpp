#include <iostream>
#include <vector>

using namespace std;

/*Insertion function*/
void Insert(int A[], int n){
    /*Insert element to the end of the array*/
    int i = n;
    int temp = A[n];

    /*Reallocate new element*/
    while(i>0 && temp>A[i%2 == 0 ? (i/2)-1: i/2]){
        A[i] == A[i%2 == 0 ? (i/2) - 1:i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }

    A[i] = temp;
}

/*Prints out elements inside array*/
template <class T>
void Print(T& vec, int n){
    cout << "Max Heap: " <<flush;
    for(int i=0; i<n; i++){
        cout << vec[i] << flush;
        if(i < n-1){
            cout << ", " <<flush;
        }
    }
}

int main(){
    int a[] = {10,23,45,78,99,32};
    Insert(a, 5);
    Print(a, sizeof(a)/sizeof(a[0]));
}