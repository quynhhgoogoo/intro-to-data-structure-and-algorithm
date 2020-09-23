/*reference : another name given to a variable*/
#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int &r = a;     /*reference initialization*/

    cout<<r<<endl;        /*10*/
    r++;
    cout<<r<<endl;        /*11*/
    cout<<a<<endl;        /*11*/
}