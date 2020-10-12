#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;     /*create array dynamically*/
};

/*Initialize the queue*/
void createQueue (struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

/*Enqueue the queue/ Adding elements*/
void enqueue(struct Queue *q, int x){
    if(q->rear == q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

/*Dequeue the queue*/
int dequeue(struct Queue *q){
    int x = -1;
    if (q->front == q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

/*Display queue*/
void Display(struct Queue q){
    for(int i=q.front; i<=q.rear; i++){
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main(){
    struct Queue q;
    createQueue(&q, 4);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    dequeue(&q);

    Display(q);

    return 0;
}