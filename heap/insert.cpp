#include <iostream>
#include <vector>

using namespace std;

/*Insertion inplace function*/
void InsertInplace(int A[], int n){
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

/*Insertion function*/
void Insert(vector<int>& vec, int key){
    /*Insert key at the end*/
    auto i = vec.size();
    vec.emplace_back(key);

    /*Rearrange elements*/
    while(i>0 && key > vec[i%2==0 ? (i/2)-1: i/2]){
        vec[i] = vec[i%2 == 0 ? (i/2) - 1:i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }

    vec[i] = key;
}

/*Creating heap using inplace*/
void createHeapInplace(vector<int>& vec, int A[], int n){
    for(int i=0; i<n; i++){
        Insert(vec, A[i]);
    }
}    

/*Creating heap*/
void createHeap(vector<int>& vec, int A[], int n){
    for(int i=0; i<n; i++){
        InsertInplace(A, i);
    }
}

/*Prints out elements inside array*/
template <class T>
void Print(T& vec, int n, char c){
    cout << "Max Heap: " << c << ":[" <<flush;
    for(int i=0; i<n; i++){
        cout << vec[i] << flush;
        if(i < n-1){
            cout << ", " <<flush;
        }
    }
    cout << "]" << endl;
}

int main(){
    cout<<"Creating Heap"<<endl;
    int a[] = {10,23,45,78,99,32};
    Print(a, sizeof(a)/sizeof(a[0]), 'a');

    vector<int> v;
    createHeap(v, a, sizeof(a)/sizeof(a[0]));
    Print(v, v.size(), 'v');

    cout <<"Inplace insertion"<<endl;
    InsertInplace(a, 5);
    Print(a, sizeof(a)/sizeof(a[0]), 'a');

    return 0;
}