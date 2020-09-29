#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head;

/*create ring buffer based on given array*/
void create(int A[], int n){
    int i;
    struct Node *t, *last;

    /*create first node in ring buffer*/
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

/*Calculates the total amount of nodes inside ring buffer*/
int Length(){
    struct Node *p = head;
    int len = 0;

    do{
        len++;
        p = p->next;
    }
    while(p != head);
    return len;
}

/*Displays elements inside ring buffer*/
void Display(struct Node *p){
    do{
        printf("%d ", p->data);
        p = p->next;
    }
    while(p != head);
    printf("\n");
}

/*Display elements inside ring buffer recursively*/
void RDisplay(struct Node *p){
    static int flag = 0;
    if(p != head || flag == 0){
        flag = 1;
        printf("%d ", p->data);
        RDisplay(p->next);
    }
    flag = 0;
}

/*Insert new node into ring buffer*/
void Insert(int index, int value){
    struct Node *p = head, *t;
    int i;

    if(index <0 || index > Length()){
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;

    /*if node is inserted before current first node*/
    if(index == 0){
        if(head == NULL){
            head = t;
            head->next = head;
        }
        else{
            /*move pointer around the circular list until it reaches last node*/
            while(p->next != head){
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    /*if node is inserted after 2nd++ node*/
    else{
        for(i=0; i< index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index){
    struct Node *q;
    int i, x;

    if(index < 0 || index >Length()){
        return -1;
    }
    /*if delete head node*/
    if(index == 1){
        while(p->next != head){
            p = p->next;
        }
        x = head->data;
        /*if head is the only node inside ring buffer*/
        if(head == p){
            free(head);
            head = NULL;
        }
        else{
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }

    else{
        /*traverse pointer to the node before deleted node*/
        for(int i=0; i<index-2; i++){
            p = p->next;
        }

        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
}

int main(){
    int A[] = {2,3,4,5,6};

    create(A, 5);
    Insert(0, 12);
    Delete(head, 3);
    Display(head);

    return 0;
}