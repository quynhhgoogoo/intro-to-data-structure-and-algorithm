#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;

/* Insert elements in binary search tree */
void Insert(int key){
    struct Node *t = root;
    struct Node *r, *p;

    /* If tree is empty */
    if(root == NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root=p;
        return;
    }

    /* Start iterating through binary tree */
    while(t != NULL){
        r = t;
        if(key < t->data){
            t = t ->lchild;
        }
        else if(key > t->data){
            t = t->rchild;
        }
        /* If key is found */
        else{
            return;
        }
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data )
        r->lchild = p;
    else
        r->rchild = p;
}

struct Node * Search(int key){
    struct Node *t = root;
    while( t != NULL){
        if (key == t->data){
            printf("\nElements %d is found", key);
            return t;
        }
        else if (key < t->data){
            t = t->lchild;
        }
        else{
            t = t->rchild;
        }
    }
    printf("\nElements %d is not found", key);
    return NULL;
}

/* Print results in inorder traversal */
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

int main(){
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);

    struct Node *temp;
    temp = Search(20);
    temp = Search(80);

    return 0;
}