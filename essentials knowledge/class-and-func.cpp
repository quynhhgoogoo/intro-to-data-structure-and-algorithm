#include <iostream>

using namespace std;

class Rectangle{
    /*paras were declared privately*/
    int length;
    int breadth;

/*funcs were declared publicly*/

Rectangle(int l, int b){
    /*constructor*/
    length = l;
    breadth = b;
}

int area(){
    return length*breadth;
}

void changeLength(int l){
    length = l;
}

int main(){
    Rectangle r(10,5);

    //r.initialize(10, 5);
    r.area();
    r.changeLength(20);
}
};