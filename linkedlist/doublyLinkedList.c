# include <stdio.h>
#include <stdlib.h>

/* Create a structure for a node inside doubly linkedlist */
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}* first = NULL;


/* Create a doubly linkedlist. Given an array and number of elements inside the array */
void create (int A[], int n){
    struct Node *t, *last;
    int i;

    /* Create the first node inside a doubly linkedlist */
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;

    /* Set last pointer to the first node*/
    last = first;

    /* Create new node inside linkedlist itteratively */
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        /* Link current node to the previous node and last node */
        t->next = last->next;
        t->prev = last;

        /* Link prev node to current node */
        last->next = t;
        last = t;
    }
}


/* Display element inside doubly linkedlist */
void Display(struct Node *p){
    while (p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


/* Calculate the length of string */
int Length (struct Node *p){
    int len = 0;

    while(p) {
        len++;
        p = p->next;
    }
    return len;
}


int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    printf("\n Length is : %d\n", Length(first));

    Display(first);

    return 0;
}