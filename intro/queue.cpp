#include <iostream>
#include <queue>

using namespace std;

class IntQueue{
    int *element;
    int max_size;
    int head;
    int tail;

    public:
        IntQueue(int s){
            max_size = s;
            head = -1;
            tail = -1;

            /*Constructor for elements*/
            element = new int[s];
        }

        ~IntQueue(){
            delete[] element;
        }

        void enqueue(int x){
            if(tail == max_size -1){
                runtime_error("Queue Full");
            }
            tail ++;
            element[tail] = x;
        }

        int dequeue(){
            if(head == tail){
                runtime_error("Queue empty");
            }
            head ++;    /*Popping element out by increasing head*/
            return element[head];
        }

        bool empty(){
            return head == tail;
        }
};

int main(){
    IntQueue i(5);
    i.enqueue(5);
    i.enqueue(1);
    i.enqueue(6);

    cout<<"i.dequeue "<<i.dequeue()<<endl;
    cout<<"i.dequeue "<<i.dequeue()<<endl;
    cout<<"i.dequeue "<<i.dequeue()<<endl;
    cout<<"Empty :"<<i.empty()<<endl;
}