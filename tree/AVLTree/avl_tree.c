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


/* LR Rotation */
struct Node *LRRotation(struct Node *p){
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    /* Relocate child node of new root */
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    /* Assign new node to new childs */
    plr->lchild = pl;
    plr->rchild = p;

    /* Track height of each node after rotation */
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p){
        root = plr;
    }

    return plr;
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

/* RL Rotation */
struct Node *RLRotation(struct Node *p){
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    /* Relocate child node of new root */
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    /* Assign new node to new childs */
    prl->rchild = pr;
    prl->lchild = p;

    /* Track height of each node after rotation */
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root == p){
        root = prl;
    }

    return prl;
}

/* RR Rotation */
struct Node *RRRotation(struct Node *p){
    struct Node *pr = p->rchild;
    struct Node *prr = pr->rchild;

    /* Place pointer at its parent's node position */
    pr->lchild = p;
    p->rchild = prr;
    
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root==p){
        root = pr;
    }

    return pr;
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

/* Deletion function */
struct Node *Delete(struct Node *p, int key){
    
    /*if tree is empty*/
    if(p == NULL){
        return NULL;
    }

    /* if the node is going to be deleted is leaf node */
    if(p->lchild == NULL && p->rchild == NULL){
        /* tree has a single node */
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }

    /* search for the node with given key */
    if(key < p->data){
        p->lchild = Delete(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild, key);
    }
    /* if node is found */
    else{
        struct Node *q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } 
        else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }       
    }

    /* Update node's height */
    p->height = NodeHeight(p);

    /* Apply rotation to balance tree */
    if (BalanceFactor(p) == 2 & BalanceFactor(p->lchild) == 1){
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 & BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    }
    /* can used both LL or RL Rotation */
    else if (BalanceFactor(p) == 2 & BalanceFactor(p->lchild) == 0){
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 & BalanceFactor(p->lchild) == 1){
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 & BalanceFactor(p->lchild) == -1){
        return RLRotation(p);
    }
    /* can be both RR or KR */
    else if (BalanceFactor(p) == -2 & BalanceFactor(p->lchild) == 0){
        return RRRotation(p);
    }  
}


int main(){
    root = RInsert(root,40);
    RInsert(root, 5);
    RInsert(root, 22);
    RInsert(root,20);

    Delete(root,22);

    return 0;
}