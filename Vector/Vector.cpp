#include <iostream>

using namespace std;


// A vector is a dynamic array that can perform many useful operations

class Vector{
    private:
        int capacity; // Capacity is the total memory allocated for the vector
        int length; // Length is the number of elements
        int * arr;

        // Allocate more memory to the array

        void moreCapacity(){
            capacity *= 2;
            int * biggerArr = new int [capacity];
            for(int i = 0; i < length ; i++){
                biggerArr[i] = arr[i];
            }
            arr = biggerArr;
        }

    public:
        Vector(){
            capacity = 2; // The initial capacity, you can assume any number
            length = 0;
            arr = new int[capacity];
        }

        int getLength() const{
            return length;
        }

        // Subscript operator to access and change an element at index
        // It has O(1) time complexity for both best, average, and worst case

        int& operator[](const int& index) const {
            return arr[index];
        }

        // Insert at given index an element
        // It has O(1) time complexity for the best case
        // It has O(n) time complexity for both the average and worst case

        void insertAt(int index, int element){
            length++;

            if(length > capacity){
                moreCapacity();
            }

            for(int i = length - 1; i > index; i--){
                arr[i] = arr[i-1];
            }

            arr[index] = element;
        }

        // Insert at last index an element
        // It has O(1) time complexity for best, average and worst case

        void insertAtLast(int element){
            length++;

            if(length > capacity){
                moreCapacity();
            }

            arr[length - 1] = element;
        }

        // Delete element at index
        // It has O(1) time complexity for best case
        // It has O(n) time complexity for average and worst case

        void deleteAt(int index){
            length--;

            for(int i = index; i < length; i++){
                arr[i] = arr[i+1];
            }
        }

        // Find the index of the fist occurrence of an element
        // It has O(1) time complexity for best case
        // It has O(n) time complexity for average and worst case

        int findFirst(int element){
            for(int i = 0; i < length; i++){
                if(arr[i] == element){
                    return i;
                }
            }

            return -1;
        }

        // Bubble sort algorithm
        // It has O(n^2) time complexity for best, average, worst case
        // It can be modified to have a complexity of O(n) for the best case
        // Check https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html to visualize bubble sort

        void bubbleSort(){
            for(int i = 0; i < length - 1; i++){
                for(int j = 0; j < length - i - 1; j++){
                    if(arr[j] > arr[j+1]){
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
        }
};

// Binary Search Algorithm
// It has O(1) time complexity for best case
// It has O(log(n)) time complexity for both average case and worst case
// Check http://www.cs.armstrong.edu/liang/animation/web/BinarySearch.html to visualize binary search

int binarySearch(const Vector& vec, const int& element, int first, int last){

    if(first <= last){
        int middle = (first + last)/2;

        if(element == vec[middle]){
            return middle;
        }
        else if(element > vec[middle]){
            return binarySearch(vec, element, middle + 1, last);
        }
        else {
            return binarySearch(vec, element, first, middle - 1);
        }
    }
    else {
        return -1;
    }
}

int main()
{
    Vector vec;

    vec.insertAtLast(5);
    vec.insertAtLast(100);
    vec.insertAtLast(3);

    vec.bubbleSort();

    for(int i = 0; i < vec.getLength(); i++){
        cout << vec[i] << " ";
    }

    cout << endl;

    vec.insertAt(1, 3000);

    vec.bubbleSort();

    for(int i = 0; i < vec.getLength(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    vec.deleteAt(vec.findFirst(100));

    for(int i = 0; i < vec.getLength(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    int index = binarySearch(vec, 3, 0, vec.getLength()-1);
    vec[index] = 6;

    for(int i = 0; i < vec.getLength(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
