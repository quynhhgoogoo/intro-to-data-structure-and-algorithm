#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*Initialize structure for tree's node*/
class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

/*initialize tree*/
class Tree{
    private:
        Node *root;
    public:
        Tree();
        ~Tree();
        void CreateTree();
        void DestroyTree(Node *p);
        void Preorder(Node *p);
        //Passing private parameter inside constructor
        void Preorder(){
            Preorder(root);
        }
        void Inorder(Node *p);
        void Inorder(){
            Inorder(root);
        }
        void Postorder(Node *p);
        void Postorder(){
            Postorder(root);
        }
        void Levelorder(Node *p);
        void Levelorder(){
            Levelorder(root);
        }
        int Height(Node *p);
        int Height(){
            return Height(root);
        }
        void iterativePreorder(Node *p);
        void iterativePreorder(){
            iterativePreorder(root);
        };
        void iterativeInorder(Node *p);
        void iterativeInorder(){
            iterativeInorder(root);
        };
        void iterativePostorder(Node *p);
        void iterativePostorder(){
            iterativePostorder(root);
        };
};

/*Instructor of tree*/
Tree::Tree() {
    root = nullptr;
}

/*Destroy the tree recursively*/
void Tree::DestroyTree(Node *p){
    if (p){
        DestroyTree(p->lchild);
        DestroyTree(p->rchild);
        delete p;
    }
}

/*Destructor of tree*/
Tree::~Tree(){
    DestroyTree(root);
};

/*Create a new tree using queue*/
void Tree::CreateTree(){
    Node *p;
    Node *t;
    int x;
    queue <Node *> q;

    /*Generate a new node for tree's root*/
    root = new Node;
    cout << "Enter root value: " << flush;
    cin >> x;

    /*Create a root at the end of the queue*/
    root->data = x;
    root->rchild = nullptr;
    root->lchild = nullptr;
    q.emplace(root);

    while( !q.empty()){
        /*Move pointer to the new address and pop the one element out*/
        p = q.front();
        q.pop();

        /*Create new node for left child and add in queue*/
        cout << "Enter left child value of" << p->data << ": " <<flush;
        cin >> x;

        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        /*Create new node for right child and add in queue*/
         cout << "Enter right child value of" << p->data << ": " <<flush;
        cin >> x;

        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }

    }
}

/*Calculate tree's height*/
int Tree::Height(Node *p){
    int l = 0;
    int r = 0;
    /*If tree is empty*/
    if(p == nullptr){
        return 0;
    }

    l = Height(p->lchild);
    l = Height(p->rchild);

    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
}

/*Tranversing through tree recursively*/
void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
 
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

/*Tranversing through tree itteratively*/

int main(){
    Tree bt;

    cout << "Creating a new tree" <<endl;
    bt.CreateTree();

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    return 0;
}