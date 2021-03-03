#include <iostream>

using namespace std;

/*Swapping two elements*/
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

/*Delete element in heap*/
int Delete(int A[], int n){
    /*Remove root element and move element from final leaf to root*/
    int val = A[0];
    A[0] = A[n-1];

    /*Mark root element and left child*/
    int i = 0;
    int j = 2*i + 1;

    while(j<n-1){
        /*Compare left and right childs*/
        if (A[j] < A[j+1]){
            j =j+1;
        }

        /*Compare parent and its largest child*/
        if (A[i] < A[j]){
            swap(A, i, j);
            i = j;
            j = 2*i+1;
        }
        else{
            break;
        }
    }
    return val;
}

void Heapify(int A[], int n){
    /* Number of leaf elements: (n+1)/2
       Index of last leaf element's parent: (n/2)-1*/

    for(int i=(n/2)-1; i>=0; i--){
        int j = 2*i+1;                 /*left child of current i*/

        while(j<n-1){
        /*Compare left and right childs*/
            if (A[j] < A[j+1]){
                j =j+1;
            }

            /*Compare parent and its largest child*/
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2*i+1;
            }
            else{
                break;
            }
        }
    }
}

/*Display elements*/
template <class T>
void Print(T&vec, int n){
    for(int i=0; i<n; i++){
        cout << vec[i] << flush;
        if(i<n-1){
            cout << " " << flush;
        }
    }
}

int main(){
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Print(A, sizeof(A)/sizeof(A[0]));
    cout << endl;

    cout << "Deleting elements: ";
    for(int i=0; i<sizeof(A)/sizeof(A[0])-1; i++){
        cout << Delete(A, sizeof(A)/sizeof(A[0])) << " ";
    }
    Print(A, sizeof(A)/sizeof(A[0]));
    cout << endl;

    cout << "Heapifying: ";
    Heapify(A, sizeof(A)/sizeof(A[0]));
    Print(A, sizeof(A)/sizeof(A[0]));

    return 0;
}