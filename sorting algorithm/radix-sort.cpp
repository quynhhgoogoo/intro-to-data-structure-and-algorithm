#include <iostream>
#include <cmath>

#define DEC 10

using namespace std;

/* Linkedlist node */
class Node{
    public:
        int value;
        Node* next;
};


/* Insert new element into Linkedlist */
void Insert(Node **ptrBins, int value, int idx){
    /* initialize a new node */
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    /* If linkedlist is empty */
    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;
    }
    else{
        /* Insert element in the end of linkedlist */
        Node *p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}


/* Delete a node in linkedlist */
int Delete(Node **ptrBins, int idx){
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

/* Print out array's content */
void Print(int A[], int n){
    for(int i = 0; i < n; i++) 
        printf("%d ",A[i]); 
    printf("\n");
}


/* Searching for the largest element inside array */
int findMax(int A[], int n){
    int max = INT16_MIN;
    int i;

    for (i = 0; i < n; i ++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}


/* Initialize bin array with nullptr */
void initializeBins (Node **p, int n){
    for (int i = 0; i < n; i++){
        p[i] = nullptr;
    }
}


/* Return index into bin array while transfering elements from A to bin */
int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) %10;
}


/* Count the number of digits in a given number */
int CountDigits (int x){
    int count = 0;
    
    while (x != 0){
        x = x/10;
        count ++;
    }
    return count;
}


/* RadixSort function */
void RadixSort(int A[], int n){
    int max = findMax(A, n);
    int no_of_passes = CountDigits(max);

    /* Initialize bin array for sorting decimal values */
    Node **bins = new Node* [DEC];
    initializeBins(bins, DEC);

    /* Update A and bins */
    for (int pass = 0; pass < no_of_passes; pass++){

        /* Update bins based on A values */
        for (int i = 0; i < n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }

        /* Update A with sorted element from bin */
        int i = 0, j = 0;
        while (i < DEC){
            while (bins[i] != nullptr){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
    }

    /* Delete bin array */
    delete [] bins;
}


int main() {
 
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n);
    RadixSort(A, n);
    Print(A, n);
 
    return 0;
}