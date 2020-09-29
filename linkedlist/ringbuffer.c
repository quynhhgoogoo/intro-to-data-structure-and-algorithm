#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head;

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

int main(){
    int A[] = {2,3,4,5,6};
    create(A, 5);
    Display(head);

    return 0;
}