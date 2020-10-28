#include <stdio.h>
#include <stdlib.h>

#ifndef binary_tree_h
#define binary_tree_h

/*Node is created to store the value of tree's elements*/
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

/*Queue is a collection of nodes. Created to store the address of node*/
struct Queue{
    int size;
    int front;
    int rear;
    Node**Q;
};

/*Initialize a new queue*/
void createQueue(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node**)malloc(q->size*sizeof(Node *));
}

/*Enqueue the queue*/
void enqueue(struct Queue *q, Node *x){
    if(q->rear = q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

/*Dequeue the queue*/
Node* dequeue(struct Queue *q){
    Node* x = NULL;

    if (q->front == q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

/*Check if queue is empty*/
int isEmpty(struct Queue q){
    return q.front==q.rear;
}

#endif