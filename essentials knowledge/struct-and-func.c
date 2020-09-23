#include <stdio.h>

struct Rectangle{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r1, int l, int b){
    r1->length = l;
    r1 ->breadth = b;
}

int area(struct Rectangle r){
    return r.length*r.breadth;
}

void changeLength(struct Rectangle *r2, int l){
    r2->length = l;
}

int main(){
    struct Rectangle r;

    initialize(&r, 10, 5);
    area(r);
    changeLength(&r, 20);
}