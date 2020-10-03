#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

/*first: points to first ll.
  second: points to 2nd ll
  third: points to newly merged ll*/

struct Node *first = NULL, *second = NULL, *third = NULL;

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
    printf("\n");
}

/*concatenating two linkedlist together*/
void Concat(struct Node *p, struct Node *q){
    third = p;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
}

/*merge two sorted linkedlists together*/
void MergeLinkedList(struct Node *p, struct Node *q){
    struct Node *last;

    /*create the first node in the newly merged linkedlist*/
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        third = last = q;
        q = q ->next;
        last->next = NULL;
    }

    /*second ++ node*/
    while(q != NULL && p!= NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    /*adding last node to ll*/
    if(p){
        last->next = p;
        last = p;
    }
    if(q){
        last->next = q;
        last = q;
    }
}

int main(){
    int A[] = {3,3,5,7,9,20,30};
    int B[] = {2,3,70};

    first = Create_LinkedList(first, A, 6);  
    Display_LinkedList(first);

    second = Create_LinkedList(second, B, 3);  
    Display_LinkedList(second);
    
    MergeLinkedList(first,second);
    Display_LinkedList(third);

    return 0;
}