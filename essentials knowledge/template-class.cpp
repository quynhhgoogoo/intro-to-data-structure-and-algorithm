/*template class: using the same class to different data types*/

#include <iostream>

using namespace std;

template <class T>
class Airthametic{
    private:
        /*T can be int, float, long int, etc any kind of datatypes*/
        T a;
        T b;
    public:
        Airthametic(T a, T b);
        T add();
        T sub();
};

template <class T>
Airthametic <T> :: Airthametic(T a, T b){
    this->a = a;
    this->b = b;
}

template <class T>
T Airthametic <T>::add(){
    T c;
    c = a + b;
    return c;
}

template <class T>
T Airthametic <T>::sub(){
    T c;
    c = a - b;
    return c;
}

int main(){
    /*Initialize an object with datatypes as intergers*/
    Airthametic<int> ar(10,5);
    cout<<ar.add()<<endl;
    Airthametic<float> ar(1.3,5.2);
    cout<<ar.sub()<<endl;
}