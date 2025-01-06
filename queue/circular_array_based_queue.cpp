#include <iostream>
using namespace std;

class CircularQueue{
private:
    int* arr;
    int maxSize;
    int front; // for circular implementation i.e avoid shifting elements to the left once dequeued
    int rear;  // for circular implementation i.e avoid shifting elements to the left once dequeued
    int size;

public:
    CircularQueue(int size = 10){
        maxSize = size;
        arr = new int(maxSize);
        size = 0;
        rear = -1;
        front = -1;
    }
    ~CircularQueue(){
        delete[] arr;
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == maxSize;
    }
    void enqueue(int value){
        if(isFull()){
            cout <<"Queue if full";
            return;
        }
        rear = rear+1 % maxSize;  // here if the queue is not empty, it wouldnt affect the front, just the rear
        arr[rear] = value;
        size++;

        if(front == -1){  // if it was empty(front == -1) we need to update the front since front and rear are the same
            front = rear;
        } 
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue empty";
            return;
        }
        int temp = arr[front];
        front = front+1 % maxSize;

        size--;

        if(size == 0){ // if dequeuing it cause the array to be empty, the it will affect rear so,
            front = rear = -1;
        }
        return temp;
    }
    int peek(){
        if(isEmpty()){
            cout << "Queue empty";
            return;
        }
        return arr[front];
    }
    
};
