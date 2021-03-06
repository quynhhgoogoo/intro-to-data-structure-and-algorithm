/*Pointer: an address variable which stores address of data, not the data itself
           is used to access to data indirectly*/
#include <stdio.h>

int main(){
    int a = 10;      /*Data variable*/
    int *p;         /*Access variable*/
    p = &a;         /*Initialization, address of data variable is given to p*/

    printf("%d ", a);        /*10*/
    printf("%d ", p);        /*p = &a = address of variable a*/
    printf("%d ", *p);       /*a = *p = value of a*/

    /*same initialization*/
    int *p1 = &a;
    printf("Test a bit ");
    printf("%d %d %d", *p1, a, p1);
}
