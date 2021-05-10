/*Generate a tree from traversal*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node{
    public:
        Node* lchild;
        int data;
        Node *rchild;

        Node(){};
        Node(int data);
};

class Tree{
    private:
        Node *root;
    public:
        Tree();
        ~Tree();
        void Preorder(Node *p);
        void Preorder(){
            Preorder(root);
        }
        Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
        int Height(Node *p);
        int Count(Node *p);
        int Sum(Node *p);
        int CountDeg2Node(Node *p);
};

Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {}

/*initialize a node*/
Node::Node(int data){
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

/*Searching function, return the position of element*/
int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for(int i=inStart; i<=inEnd; i++){
        if(inArray[i] == data){
            return i;
        }
    }
    return -1;
}

/*Calculate tree's height*/
int Tree::Height(Node *p){
    int l = 0;
    int r = 0;

    if(p != nullptr){
        l = Height(p->lchild);
        r = Height(p->rchild);
        return l+r+1;
    }
    return 0;
}

/*Calculate sum of tree*/
int Tree::Sum(Node *p){
    int l = 0;
    int r = 0;
    if(p != nullptr){
        l = Sum(p->lchild);
        r = Sum(p->rchild);
        return l+r+p->data;
    }
    return 0;
}

int Tree::CountDeg2Node(Node *p){
    int l = 0;
    int r = 0;
    if(p != nullptr){
        l = CountDeg2Node(p->lchild);
        r = CountDeg2Node(p->rchild);
        if(p->lchild && p->rchild){
            return l+r+1;
        }
        else{
            return l+r;
        }
    }
    return 0;
}

Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd){
    static int preIndex = 0;

    /*if tree is empty*/
    if(inStart > inEnd){
        return nullptr;
    }

    /*create a node for elements in preorder array*/
    Node *node = new Node(preorder[preIndex]);

    if(inStart == inEnd){
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);

    return node;
}

int main(){
    Tree bt;
    
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node* T = bt.generateFromTraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    bt.Preorder(T);
 
    return 0;
}