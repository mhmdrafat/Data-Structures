#include <iostream>

using namespace std;

class Queue {
    private:
        int length; // or size
        int capacity;
        int first; // or front
        int rear; // or last
        int * arr;


        bool isFull(){
            return length == capacity;
        }

        bool isEmpty(){
            return length == 0;
        }
    public:
        Queue(){
            length = 0;
            capacity = 5;
            first = 0;
            rear = capacity - 1;
            arr = new int[capacity];
        }

        int getRear(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return INT_MIN;
            }
            return arr[rear];
        }

        int getfirst(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return INT_MIN;
            }
            return arr[first];
        }

        void enQueue(int element){
            if(isFull()){
                cout << "Queue is full" << endl;
                return;
            }
            else {
                rear = (rear + 1) % capacity;
                arr[rear] = element;
                length += 1;
            }
        }

        int deQueue(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return INT_MIN;
            }
            else {
                int item = arr[first];
                first = (first + 1) % capacity;
                length -= 1;
                return item;
            }
        }

        ~Queue(){
            delete [] arr;
        }
};

int main()
{
    Queue q;

    q.enQueue(5);
    q.enQueue(3);
    q.enQueue(1);
    q.enQueue(4);
    q.enQueue(100);
    cout << q.deQueue() << endl;
    q.enQueue(7000);
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    return 0;
}
