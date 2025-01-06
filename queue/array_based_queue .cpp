#include <iostream>
using namespace std;

class ArrayQueue{
private:
    int* arr;
    int maxSize;
    int front;
    int rear;
    int size;
public:
    ArrayQueue(int capacity = 10){
        maxSize = capacity;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
        size = 0;
    }
    ~ArrayQueue(){
        delete[] arr;
    }
    bool isFull(){
        return size = maxSize;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(int value){
        if(isFull()){
            cout << "Queue Overflow";
            return;
        }
        arr[++rear] = value;
        size++; 

        if (front == -1){    // if it was empty(front == -1) we need to update the front since front and rear are the same
            front = rear;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow";
            return;
        }
        int temp = arr[front];
        front++;
        size--;
        return temp;
    }
    int peek(){
        if(!isEmpty()){
            return arr[front];
        }
        return 0;
    }
    
}; 