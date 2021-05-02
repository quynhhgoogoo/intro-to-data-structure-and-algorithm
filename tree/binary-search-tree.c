#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;

/* Create BST from Preorder 
    input: preorder BST as an array and array's size*/
void createFromPreorder(int *pre, int n){
    int i = 0;
    struct Node *t;
    struct Node *p = root;
    
    /* Create root node */
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = pre[i];
    root->lchild = NULL;
    root->rchild = NULL;

    /* Create a stack to store the check data */
    struct Stack stk;
    create(&stk);
    
    while(i < n){
        /* If node is inserted as a left child of current node */
        if (pre[i] < p->data){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i];
            t->lchild = NULL;
            t->rchild = NULL;
            /* Assign new value to as a left child of current node */
            p->lchild = t;
            /* Save current node's value to stack */
            push(&stk, p->data);
            p = t;
            i++; 
        }
        else{
            if(pre[i] > p->data && pre[i] < empty(pop(p))){
                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = pre[i];
                t->lchild = NULL;
                t->rchild = NULL;
                p->rchild = t;
                p = t; 
            }
            else{
                p = stackTop(stk);
                pop(&stk);
            }
        }
    }
}

/* Insert elements in binary search tree itteratively */
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

/* Insert binary search tree recursively */
struct Node * RInsert(struct Node *p, int key){
    struct Node *t = NULL;

    if(p == NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data){
        p->lchild = RInsert(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = RInsert(p->rchild, key);
    }
    return p;
}

/* Searching function for binary search tree*/
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

/* Calculate tree's height from an input node*/
int Height(struct Node *p){
    int x, y;

    if (p == NULL){
        return 0;
    }

    x = Height(p->lchild);
    y = Height(p->rchild);

    return x>y?x+1:y+1;
}

/* Search for inorder precessor of a node */
struct Node *InPre(struct Node *p){
    while(p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}

/* Search for inorder successor of a node */
struct Node *InSuc(struct Node *p){
    while(p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

/* Delete a node based on its value from binary search tree */
struct Node *Delete(struct Node *p, int key){
    struct Node *q;

    /* if tree is empty */
    if(p==NULL){
        return NULL;
    }
    
    /* if delete node is a leaf node */
    if (p->lchild == NULL && p->rchild == NULL){
        if(p==root){
            root == NULL;
        }
        free(p);
        return NULL;
    }
    
    /* Iterate through binary search tree to search for the key value */
    if(key < p->data){
        p->lchild = Delete(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild, key);
    }

    /* If key value is found */
    else {
        /* Check the height of inorder precessor and successor node */
        if (Height(p->lchild) > Height(p->rchild)){ 
            /* Move precessor node to root */
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else {
            q = InSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}


int main(){
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);

    Inorder(root);
    Delete(root, 10);
    Inorder(root);

    struct Node *temp;
    temp = Search(20);
    temp = Search(80);

    int A = [30,50,67,80,12,45];
    createFromPreorder(&A, 6);
    Inorder(root);

    return 0;
}