/*Implement a binary tree with queue*/

#include "binary_tree.h"

struct Node *root= NULL;

/*Initialize a tree*/
void createTree(){

    /*Initialize nodes and queue*/
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    /*Initialize tree's root*/
    printf("\nEnter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data =x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)){
        /*Move pointer to new address*/
        p = dequeue(&q);
        
        /*Adding left child*/
        printf("Enter left child ");
        scanf("%d", &x);
        
        if( x!= -1){
            /*Create new node for left child*/
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;

            /*Attach newly created left node to the tree*/
            p->lchild = t;
            enqueue(&q, t);
        }
        
        /*Adding right child*/
        printf("Enter right child ");
        scanf("%d", &x);
        
        if( x!= -1){
            /*Create new node for left child*/
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;

            /*Attach newly created left node to the tree*/
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main(){
    createTree();
    preorder(root);
    return 0;
}