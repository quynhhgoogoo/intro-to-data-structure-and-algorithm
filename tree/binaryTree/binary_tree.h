#include <stdio.h>
#include <stdlib.h>

#ifndef binary_tree_h
#define binary_tree_h

/*Node is created to store the value of tree's elements*/
struct StoreNode{
    struct StoreNode *lchild;
    int data;
    struct StoreNode *rchild;
};

/*Queue is a collection of nodes. Created to store the address of node*/
struct Queue{
    int size;
    int front;
    int rear;
    struct StoreNode **Q;
};

/* Stack structure */
struct Stack
{
    int size;
    int top;        /*points to the latest element*/
    int *S;         /*points to the array*/
};

/*Initialize a new queue*/
void createQueue(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct StoreNode **)malloc(q->size*sizeof(struct StoreNode *));
}

/*Enqueue the queue*/
void enqueue(struct Queue *q, struct StoreNode *x){
    if(q->rear = q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

/*Dequeue the queue*/
struct StoreNode* dequeue(struct Queue *q){
    struct StoreNode* x = NULL;

    if (q->front == q->rear){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

/*Initialize a stack*/
void create(struct Stack *st){
    
    printf("Enter Size");
    scanf("%d",&st->size);

    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

/*Display elements inside the stack*/
void Display(struct Stack st){
    int i;

    for(i=st.top;i>=0;i--){
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

/*Insert new node inside stack*/
void push(struct Stack *st,int x){

    if(st->top==st->size-1){
        printf("Stack overflow\n");
    }
    
    else{
        st->top++;
        st->S[st->top]=x;
    } 
}

/*Delete/Pop the latest element inside stack*/
int pop(struct Stack *st){
    int x=-1;
    
    if(st->top==-1){
        printf("Stack Underflow\n");
    }
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

/*Input : index of search element
  Function: Searching for elements's value inside stack*/

int peek(struct Stack st, int index){
    int x = -1;
    if(st.top-index+1 < 0){
        printf("Invalid index\n");
    }
    if(index>st.size){
        printf("Invalid index\n");
    }
    x = st.S[st.top-index+1];
    return x;
}

/*check if stack is empty*/
int isEmpty(struct Stack *st){
    if(st->top == -1){
        return 1;
    }
    return 0;
}

int stackTop(struct Stack st){
    if(!isEmpty(&st))
        return st.S[st.top];
    return -1;
}

#endif