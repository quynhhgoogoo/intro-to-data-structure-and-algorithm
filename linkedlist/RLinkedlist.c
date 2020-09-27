/*Includes recursive functions for linkedlist*/

#include <stdio.h>
#include <stdlib.h>

/*print nodes in linked list in ascending order recursively*/
void RDisplayA(struct Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplayA(p->next);
    }
}

/*print nodes in linked list in descending order recursively*/
void RDisplayD(struct Node *p){
    if(p!=NULL){
        RDisplayD(p->next);
        printf("%d ", p->data);
    }
}

/*count the number of nodes inside linkedlist*/
int CountNode(struct Node *p){
    int count = 0;
    
    if(p==NULL){
        return 0;
    }
    else{
        count = CountNode(p->next) + 1;
        return count;
    }
}

/*calculate the sum of linkedlist*/
int SumNode(struct Node *p){
    int sum = 0;
    
    if(p==NULL){
        return 0;
    }
    else{
        sum = SumNode(p->next) + p->data;
        return sum;
    }
}

/*find maximum in linkedlist*/
int MaxNode(struct Node *p){
    int x = 0, m = -32768;

    if(p==NULL){
        return m;
    }
    x = MaxNode(p->next);
    return x > p->data ? x:p->data;
}

/*searching value in linkedlist*/
struct Node *LinearSearch(struct Node *p, int key){
    if(p == NULL)
        return 0;
    if(key == p->data)
        return p;
    return LinearSearch(p->next, key);
}