#include <iostream>

using namespace std;

// Linked list ADT (Abstract Data Type)
// It describes the basic operations required from any linked list type (Singly, Doubly, Circular, ...)

class LinkedList{
    protected:
        virtual int getLength() = 0;
        virtual int& operator[] (const int& index) const = 0;
        virtual void insertAt(int index, int element) = 0;
        virtual void insertAtFirst(int element) = 0;
        virtual void insertAtLast(int element) = 0;
        virtual void removeAt(int index) = 0;
        virtual void removeAtFirst() = 0;
        virtual void removeAtLast() = 0;
        virtual int findFirst(int element) = 0;
        virtual void printList() = 0;
};

/*
    Singly linked list consists of connected nodes accessed through head variable
    Each node holds two variables.
    The first variable holds the data.
    The second variable holds the address of the next node.

     head            tail (tail is optional but it increases the performance)
      |               |
    -----   -----   -----
    |1| --> |5| --> |3| --> NULL
    -----   -----   -----
*/

class SinglyLinkedList: public LinkedList{
    class Node{
        public:
            int data;
            Node * next;
    };

    private:
        int length;
        Node * head;
        Node * tail;
    public:
        SinglyLinkedList(){
            length = 0;
            head = NULL;
            tail = NULL;
        }

        int getLength(){
            return length;
        }

        // It has a complexity of O(n) for average and worst case
        // It has a complexity of O(1) for best case if first element is accessed

        int& operator[] (const int& index) const{
            Node * curr = head;

            for(int i = 0; i < index; i++){
                curr = curr->next;
            }

            return curr->data;
        }

        /*
            Insert operation with O(n) complexity for average, and worst case
            Insert operation has O(1) complexity for best case if insertion at head or tail

             head                             tail
              |                                |
            -----                    -----   -----
            |1| ---|           |---> |5| --> |3| --> NULL
            -----  |    -----  |     -----   -----
                   |--> |2| ---|
                        -----
        */

        void insertAt(int index, int element){
            length++;

            Node * node = new Node();
            node->data = element;

            if(head == NULL){
                head = tail = node;
            }
            else{
                if(index == 0){
                    node->next = head;
                    head = node;
                }
                else if(index == length-1){
                    tail->next = node;
                    tail = node;
                }
                else{
                    Node * prev = NULL;
                    Node * curr = head;

                    for(int i = 0; i < index; i++){
                        prev = curr;
                        curr = prev->next;
                    }

                    prev->next = node;
                    node->next = curr;
                }
            }
        }

        /*
            Insert at first operation with O(1) complexity for best, average and worst case

                                  tail
                                   |
             head        -----   -----
              |    |---> |2| --> |1| --> NULL
            -----  |     -----   -----
            |7| ---|
            -----
        */

        void insertAtFirst(int element){
            length++;

            Node * node = new Node();
            node->data = element;

            if(head == NULL){
                head = tail = node;
            }
            else {
                node->next = head;
                head = node;
            }
        }

        // Insert at last operation with O(1) complexity for best, average and worst case

        void insertAtLast(int element){
            length++;

            Node * node = new Node();
            node->data = element;

            if(head == NULL){
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }

        // Remove operation of O(n) complexity for average and worst case
        // It has O(1) complexity for best case if removal occurred to the head element

        void removeAt(int index){
            length--;

            if(head == tail){
                head = tail = NULL;
            }
            else {
                if(index == 0){
                    head = head->next;
                }
                else if(index == length){
                    Node * prev = NULL;
                    Node * curr = head;

                    while(curr->next != NULL){
                        prev = curr;
                        curr = curr->next;
                    }

                    tail = prev;
                    prev->next = NULL;
                }
                else {
                    Node * prev = NULL;
                    Node * curr = head;

                    for(int i = 0; i < index; i++){
                        prev = curr;
                        curr = curr->next;
                    }

                    prev->next = curr->next;
                    curr->next = NULL;
                }
            }
        }

        // Remove at first operation with O(1) complexity for best, average and worst case

        void removeAtFirst(){
            length--;

            if(head == tail){
                head = tail = NULL;
            }
            else {
                head = head->next;
            }
        }

        // Remove at last operation with O(n) complexity for best, average and worst case

        void removeAtLast(){
            length--;

            if(head == tail){
                head = tail = NULL;
            }
            else {
                Node * prev = NULL;
                Node * curr = head;

                while(curr->next != NULL){
                    prev = curr;
                    curr = curr->next;
                }

                tail = prev;
                prev->next = NULL;
            }
        }

        // Find first with O(n) complexity for average and worst case
        // It has O(1) complexity for the best case if the element required is at the head

        int findFirst(int element){
            Node * curr = head;
            int index = 0;


            while(curr != NULL){
                if(curr->data == element){
                    return index;
                }
                else{
                    curr = curr->next;
                    index++;
                }
            }

            return -1;
        }

        // Print list has a complexity of O(n) for best, average and worst case

        void printList(){
            Node * curr = head;
            while(curr != NULL){
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }

};

// Selection sort of O(n^2) complexity
// It is called selection because it always selects the smallest element
// Visualize the algorithm from here https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

class DoublyLinkedList: public LinkedList{
    class Node{
        public:
            int data;
            Node * next;
            Node * prev;
    };

    private:
        int length;
        Node * head;
        Node * tail;
    public:
        DoublyLinkedList(){

        }

        int getLength(){

        }

        int& operator[] (const int& index) const{

        }

        void insertAt(int index, int element){

        }

        void insertAtFirst(int element){

        }

        void insertAtLast(int element){

        }

        void removeAt(int index){

        }

        void removeAtFirst(){

        }

        void removeAtLast(){

        }

        int findFirst(int element){

        }

        void printList(){

        }
};

int main()
{
    // Linked list testing code

    SinglyLinkedList sll;

    sll.insertAt(0, 5);
    sll.insertAt(1, 100);
    sll.insertAt(2, 1020);
    sll.printList();

    sll.insertAtFirst(-5);
    sll.printList();

    sll.insertAtLast(-10);
    sll.printList();

    sll.removeAt(3);
    sll.printList();

    sll.removeAtLast();
    sll.printList();

    sll.removeAtFirst();
    sll.printList();

    int index = sll.findFirst(100);
    cout << index << endl;

    cout << sll.findFirst(555) << endl;

    cout << sll[0] << endl;

    sll[0] = 303030;
    cout << sll[0] << endl;

    // Selection sort testing code

    int arr[5] = {5, 200, 1, 3, 222};

    selectionSort(arr, 5);

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
