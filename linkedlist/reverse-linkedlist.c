#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = NULL, *last = NULL;

/*create linkedlist by inserting element to the last*/
void Create_LinkedList(int value){
    struct Node *p = first, *t, *q;

    t = (struct Node*)malloc(sizeof(struct Node));
    t -> data = value;
    t -> next = NULL;
    
    if(first == NULL){
        first = t;
        last = t;
    }
    else{
        while(p!=NULL){
            q = p;
            p = p->next;
        }
        q->next = t;
        last = t;
    }
}

void Display_LinkedList(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

/*count the number of nodes inside linkedlist*/
int CountNode(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

/*Reverse Linkedlist by using array element*/
void ReverseElement(){
    struct Node *q = first, *p = first;
    
    /*initialize an array to store linkedlist's value*/
    int *A, i =0;
    A = (int *)malloc(sizeof(int)*CountNode(p));

    /*storing linkedlist elements inside an array*/
    while(q != NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    
    /*storing array element back to linkedlist starting from last to first node*/
    while(q != NULL){
        q->data = A[i];
        q = q->next;
        i--;
    }
}

/*Reverse linkedlist by reversing links between nodes*/
void ReverseLink(){
    struct Node *p = first, *q = NULL, *r =NULL;

    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next =r;
    }
    first = q;
}

/*Reverse linkedlist by recursive function*/
void Reverse_Recursive(struct Node *q, struct Node *p){

    if(p){
        Reverse_Recursive(p,p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

int main(){
    int A[] = {3,3,5,7,20,30,9};
    
    /*User input values inside linkedlist*/
    int num;
    while (num){
        printf("Enter an interger: ");
        scanf("%d ", &num);

        Create_LinkedList(num);
    }

    ReverseElement();
    Display_LinkedList(first);
}