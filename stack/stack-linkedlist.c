#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

/*Push a new node to stack*/
void push(int x){
    
    /*Create a new node*/
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t == NULL){
        printf("Stack is full. Cannot add more node\n");
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

/*Pop element from stack*/
int pop(){
    struct Node *t;
    int x = -1;

    if(top == NULL){
        printf("Stack is empty. Cannot pop node\n");
    }
    else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

/*Display all the elements inside stack*/
void Display(){
    struct Node *p;
    p = top;

    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);

    Display();
    pop();
    printf("%d ", pop());
    Display();

    return 0;
}