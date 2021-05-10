#include <stdio.h>

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

    return p;
}


int main(){
    return 0;
}