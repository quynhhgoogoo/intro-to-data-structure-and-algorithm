#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;        /*points to the latest element*/
    int *S;         /*points to the array*/
};

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

/*check if stack is full*/
int isFull(struct Stack st){
    if(st.top == st.size - 1){
        return 1;
    }
    return 0;
}

/*Return topmost element value inside stack*/
int stackTop(struct Stack st){
    if(!isEmpty(&st))
        return st.S[st.top];
    return -1;
}

int main(){
    struct Stack st;
    
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    printf("%d \n", peek(st,2));
    Display(st);
    
    return 0;
}