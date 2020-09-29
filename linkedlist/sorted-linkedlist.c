#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *first, *last = NULL;

/*create linkedlist by adding node to last*/
void createLinkedList(int value){
    struct Node *t, *p;
    p=first;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;

    /*if linkedlist is empty*/
    if(first == NULL){
        first = t;
        last = t;
        t->next = NULL;
    }
    else{
        while(p!=NULL){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

/*insert node inside a sorted linkedlist*/
void InsertNodeSort(struct Node *p, int value){
    struct Node *q = NULL, *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    /*if the linkedlist is empty*/
    if(first ==NULL){
       first = t;
    }
    else{
        while(p && p->data < value){
           q = p;
           p = p->next;
        }
        
        /*if node is inserted in the first position*/
        if(p==first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
   }
}

void Display_LinkedList(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

int main(){
    createLinkedList(4);
    InsertNodeSort(first,5);
    Display_LinkedList(first);
}