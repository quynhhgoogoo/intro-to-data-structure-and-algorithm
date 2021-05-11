#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int height;                /* tracking the height of each node */
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;


/* Calculate height of a node */
int NodeHeight(struct Node *p){
    int hl, hr;

    /* Calculate height of left subtree and right subtree */
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;

    /* Return higher subtree as node's height */
    return hl > hr ? hl+1 : hr+1;
}


/*Calculate Balance Factor of Node*/
int BalanceFactor(struct Node *p){
    int hl, hr;

    /* Calculate height of left subtree and right subtree */
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;

    return hl - hr;
}


/* LL Rotation */
struct Node *LLRotation(struct Node *p){
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    /* Place pointer at its parent's node position */
    pl->rchild = p;
    p->lchild = plr;
    
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root==p){
        root = pl;
    }

    return pl;
}

/* LR Rotation */
struct Node *LRRotation(struct Node *p){
    return NULL;
}

/* RL Rotation */
struct Node *RLRotation(struct Node *p){
    return NULL;
}

/* RR Rotation */
struct Node *RRRotation(struct Node *p){
    return NULL;
}


/* Insert new node to tree recursively */
struct Node * RInsert(struct Node *p, int key){
    struct Node *t = NULL;

    if(p == NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data){
        p->lchild = RInsert(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = RInsert(p->rchild, key);
    }
    p->height = NodeHeight(p);

    /* Check if tree is balance and return the suitable rotation */
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1){
        return RRRotation(p);
    }
     else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1){
        return RLRotation(p);
    }

    return p;
}


int main(){
    root = RInsert(root,10);
    RInsert(root, 5);
    RInsert(root, 2);
    
    return 0;
}