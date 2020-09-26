#include <iostream>

using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;

    public:
        /*Constructor*/
        Rectangle(){
            length = 1;
            breadth = 1;
        }
        Rectangle(int l, int b);
        
        int area();
        int perimeter();
        int getLength(){
            return length;
        }
        void setLength(int l){
            length = l;
        }
        
        /*Destructor*/
        ~Rectangle();
};

/*Initialize functions*/
Rectangle::Rectangle(int l, int b){
    length = l;
    breadth = b;
}

int Rectangle::area(){
    return length*breadth;
}

int Rectangle::perimeter(){
    return 2*(length+breadth);
}

Rectangle::~Rectangle();

int main(){
    Rectangle r(10,5);
    cout<<r.area()<<endl;
    cout<<r.perimeter()<<endl;
    r.setLength(12);
    cout<<r.getLength()<<endl;
}