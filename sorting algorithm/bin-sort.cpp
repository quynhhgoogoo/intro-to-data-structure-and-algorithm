#include <iostream>

using namespace std;


/* Linkedlist node */
class Node{
    public:
        int value;
        Node* next;
};


/* Insert new element into Linkedlist */
void Insert(Node **ptrBins, int idx){
    /* initialize a new node */
    Node* temp = new Node;
    temp->value = idx;
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


/* Print out array's content */
void Print(int A[], int n){
    for(int i = 0; i < n; i++) 
        printf("%d ",A[i]); 
    printf("\n");
}


/* bin sort function */
void BinSort(int A[], int n){
    int max = findMax(A, n);

    /* Initialize bin array with nullptr pointers */
    Node** bins = new Node* [max + 1];
    for (int i = 0; i < max + 1; i++){
        bins[i] = nullptr;
    }

    /* Update bin array from A */
    for (int i = 0; i < n; i++){
        Insert(bins, A[i]);
    }
    
    /* Transfering value from bin array back to A */
    int i = 0, j = 0;
    while (i < max + 1){
        while (bins[i] != nullptr){
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    /* Delete bin array */
    delete [] bins;
}


int main() {
    int A[] = {11,5,14,2,6,3,1};
    int n = 7; 
    
    printf("Bin sort: ");
    BinSort(A, n);
    Print(A, n);

    return 0;
}
