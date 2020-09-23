struct Rectangle
{
    /* data */
    int length;
    int breadth;
};

int main(){
    struct Rectangle *p;                                        /*object created inside stack -> static object*/
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));   /*object moved to heap* -> dynamic object/
    p->length = 10;
    p->breadth = 5;
}
