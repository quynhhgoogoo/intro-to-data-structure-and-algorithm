#include <iostream>

using namespace std;


/* Prints out the array */
template <class T>
void Print(T& vec, string s){
    int n = sizeof(vec)/sizeof(vec[0]);
    cout << s << ":[" << flush;
    for (int i = 0; i < n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << "," << flush;
        }
    }
    cout << "]" << endl;
}


/* Merges two sorted lists into one*/
template <class T>
void Merge(T& x, T& y){
    int i = 0;
    int j = 0;
    int k = 0;

    int m = sizeof(x)/sizeof(x[0]);
    int n = sizeof(y)/sizeof(y[0]);

    int z[(m + n)];
    while (i < m && j < n){
        if (x[i] < y[j]){
            z[k++] = x[i++];
        }
        else{
            z[k++] = y[j++];
        }
    }

    while (i < m){
        z[k++] = x[i++];
    }
    while (i < n){
        z[k++] = x[j++];
    }

    Print(z, "\t Z");
}


/* Merges two sorted subarrays into one array */
void MergeArray(int A[], int low, int mid, int high){
    int m = sizeof(A)/sizeof(A[0]); 
    int i = low;
    int j = mid + 1;
    int k = low;

    int B[(high + 1)];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k] = A[j++];
        }
    }

    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++){
        A[i] = B[j];
    }
}

int main(){
    int A[] = {2, 10, 18, 20, 23};
    Print(A, "\t A");

    int B[] = {4, 9, 19, 25};
    Print(B, "\t B");

    Merge(A, B);

    int D[] = {2, 5, 8, 12, 3, 6, 7, 10};
    Print(D, "\t\t D");
    MergeArray(D, 0, 3, 7);
    Print(D, " Sorted D");

    return 0;
}
