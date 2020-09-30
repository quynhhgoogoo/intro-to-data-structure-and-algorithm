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

int main(){
    struct Stack st;
    
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    Display(st);
    
    return 0;
}