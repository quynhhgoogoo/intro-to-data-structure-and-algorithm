#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

/*head: points to first node.
  tail: points to last node
  current: points current node -> is used to create a node*/

struct Node *first = NULL, *second = NULL;

/*create linkedlist based on given array*/
struct Node* Create_LinkedList(struct Node *head, int A[], int n){
    int i;
    struct Node *current, *tail;
    
    /*initialize the first node*/
    head = (struct Node*)malloc(sizeof(struct Node));
    head -> data = A[0];
    head -> next = NULL;
    
    tail = head;

    for(i=1; i<n; i++){
        /*Create a new node*/
        current = (struct Node*)malloc(sizeof(struct Node));
        current -> data = A[i];
        current -> next = NULL;

        /*Link the new node to linkedlist*/
        tail -> next = current;
        tail = current;
    }
    return head;
}

/*p points to the node where we start the tranversing process*/
void Display_LinkedList(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    int A[] = {3,3,5,7,20,30,9};
    int B[] = {3,2,70};

    first = Create_LinkedList(first, A, 5);  
    Display_LinkedList(first);

    second = Create_LinkedList(second, B, 3);  
    Display_LinkedList(second);

    return 0;
}