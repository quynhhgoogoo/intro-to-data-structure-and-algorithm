#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;    /*top pointer*/
    int *S;     /*pointer to a dynamically created array*/
};

/*Initialize a stack*/
void create(struct Stack *st)
{
    printf("Enter Size");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

/*Display a stack*/
void Display(struct Stack st){
    int i;
    for(i = st.top; i >= 0; i--){
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

/*Insert element to a stack*/
void push(struct Stack *st, int value){
    if(st->top == st->size-1){
        printf("Stack is overflow/full");
    }
    else{
        st->top++;
        st->S[st->top] = value;
    }
}

/*Delete an element in stack and return that element's value*/
int pop(struct Stack *st){
    int x = -1;

    if(st->top == -1){
        printf("Stack is underflow/empty");
    }
    else{
        st->top--;
        x = st->S[st->top];
    }
    return x;
}

int main(){
    struct Stack st;
    
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    Display(st);
    
    return 0;
}