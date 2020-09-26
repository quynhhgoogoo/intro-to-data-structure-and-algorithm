#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

/*IntStack : Stack of intergers*/

class IntStack{
    int *element;
    int max_size;
    int top_index;  /*points to the array which locates the top element of the stack*/

    public:
        IntStack(int s){
            max_size = s;
            top_index = -1;

            element = new int[s];
        }

        /*Destructor to free memory*/
        ~IntStack(){
            delete[] element;
        }

        /*Push elements onto stack*/
        void push(int x){
            if(top_index == max_size -1)
                runtime_error("stack is full");
            top_index++;
            element[top_index] = x;
        }

        /*Pop or remove element out of stack*/
        void pop(){
            if(top_index == max_size -1)
                runtime_error("stack is full");
            top_index--;
        }

        /*Get the current top element without removing it*/
        int top(){
            if(top_index == -1){
                runtime_error("Stack empty");
            return element[top_index];
            }
        }

        bool empty(){
            return top_index == -1;
        }
};

int main(){
    /*Custom stack*/
    IntStack i(5);
    i.push(20);
    i.push(10);
    cout<<"i.top() :"<<i.top()<<endl;
    i.pop();
    cout << "Empty ? :"<<i.empty()<<endl;

    return 0;
}