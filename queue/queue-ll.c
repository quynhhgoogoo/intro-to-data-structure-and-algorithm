#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

/*Add node to queue*/
void enqueue(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL){
        printf(" \nCannot create more queues.");
    }
    else{
        t->data = x;
        t->next = NULL;

        /*if node is empty*/
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

/*Remove node from queue and return the deleted elements*/
int dequeue(){
    int x = -1;
    struct Node* t;

    if(front == NULL){
        printf("\nQueue is empty. Nothing to deleted");
    }
    else{
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }

    return x;
}

void Display(){
    struct Node *p = front;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    Display();
    printf("%d ", dequeue());
    Display();

    return 0;
}