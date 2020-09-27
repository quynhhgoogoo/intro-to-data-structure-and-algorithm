#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

/*head: points to first node.
  tail: points to last node
  current: points current node -> is used to create a node*/

struct Node *head = NULL;

void Create_LinkedList(int A[], int n){
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
}

/*p points to the node where we start the tranversing process*/
void Display_LinkedList(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

/*print nodes in linked list in ascending order recursively*/
void RDisplayA(struct Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplayA(p->next);
    }
}

/*print nodes in linked list in descending order recursively*/
void RDisplayD(struct Node *p){
    if(p!=NULL){
        RDisplayD(p->next);
        printf("%d ", p->data);
    }
}

/*count the number of nodes inside linkedlist*/
int count(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

/*calculate the sum of linkedlist*/
int Sum(struct Node *p){
    int sum = 0;
    while(p){
        sum = sum + p->data;
        p = p->next;
    }
    return(sum);
}

/*find maximum value in linkedlist*/
int MaxNode(struct Node *p){
    int m = -32768;        /*minimum interger = -32768*/
    while(p){
        if(p->data>m){
            m = p->data;
        }
        p=p->next;
    }
    return m;
}

/*Searching value inside LinkedList*/
struct Node *LinearSearch(struct Node *p, int key){
    while(p!=NULL){
        if(key == p->data){
            return p;
        }
        p=p->next;
    }
}

int main(){
    int A[] = {3,5,7,20,9};

    Create_LinkedList(A, 5);
    
    RDisplayA(head);
    RDisplayD(head);
    //Display_LinkedList(head);

    printf("/nMaximum value of linkedlist is: %d ", MaxNode(head));
    printf("%d", LinearSearch(head, 20));

    return 0;
}