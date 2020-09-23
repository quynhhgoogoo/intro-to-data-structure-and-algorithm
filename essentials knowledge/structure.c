struct Rectangle{
    int length;
    int breadth;
};

int main(){
    struct Rectangle r;             /*declaration*/
    struct Rectangle r={10,5};      /*initialization*/
    r.length = 15;
    r.breadth = 10;
    printf("Area of Rectangle is %d", r.length*r.breadth);
}