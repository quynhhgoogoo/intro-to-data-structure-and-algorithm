#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    private:
        Node *first;
    public:
        LinkedList(){
            first = NULL;
        }
        LinkedList(int A[], int n);
        ~LinkedList();

        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        int Length();
};

/* Input : array and number of nodes want to be allocated
Linkedlist constructor */
LinkedList :: LinkedList(int A[], int n){
    Node *last, *t;
    int i = 0;

    /*Create first new node in LinkedList*/
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    
    last = first;

    for(i=1; i<n; i++){
        /*Create a new node on heap*/
        t = new Node;
        t->data = A[i];
        t->next = NULL;

        /*Assign *last to newly created node*/
        last->next = t;
        last = t;
    }
}

/*Linkedlist destructor*/
LinkedList :: ~LinkedList(){
    Node *p = first;
    while(p){
        first = first->next;
        delete(p);
        p = first;
    }
}

/*Display elements inside linkedlist*/
void LinkedList :: Display(){
    Node *p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout<<endl;
}

/*Calculate the length of linkedlist*/
int LinkedList :: Length(){
    Node *p = first;
    int len = 0;

    while(p){
        len++;
        p = p->next;
    }
    return len;
}

/*Input: new node's value, position want to be inserted
        Insert elements to linkedlist*/
void LinkedList :: Insert(int index, int value){
    Node *t, *p = first;

    t = new Node;
    t->data = value;
    t->next = NULL;

    if(index < 0 || index > Length()){
        return;
    }
    else if (index == 0){
        t->next = first;
        first = t;
    }
    else{
        for(int i = 0; i < index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

/*Input: index want to be deleted
  Function: Delete index*/
int LinkedList :: Delete(int index){
    Node *p = first, *q = NULL;
    int x = -1;
    
    if(index < 0 || index > Length()){
        return -1;
    }
    else if(index = 1){
        x = p->data;
        first = first->next;     
        delete p;
    }
    else{
        for(int i = 0; i < index-1; i++){
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        delete p;
    }
    return x;
}

int main(){
    int A[] = {1,2,4,6,9};
    LinkedList l(A,sizeof(A)/sizeof(A[1]));

    l.Insert(4,12);
    l.Display();

    return 0;
}