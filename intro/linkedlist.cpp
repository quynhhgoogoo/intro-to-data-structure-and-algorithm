#include <iostream>

using namespace std;

struct Node(){
    int data;
    Node *next;

    /*Constructor type 1 : Initializes everything, sort of empty*/
    Node(){
        data = 0;
        next = nullptr;
    }

    /*Constructor type 2 : Node created with a given data*/
    Node(int d){
        data = d;
        next = nullptr;
    }
};