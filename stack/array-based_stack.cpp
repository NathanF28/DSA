#include <iostream>
using namespace std;

class ArrayStack {
    private:
    int capacity;
    int* arr;
    int top;
    public:
    ArrayStack(int size = 10){
        capacity = size;
        arr = new int(capacity);
        top = -1; // since we have no elements
    }
    ~ArrayStack(){
        delete[] arr;
    }
    void push(int value){
        if (top == capacity-1){
            cout << "Stack overflow";
            return ;
        }
        top++;
        arr[top] = value;
    }
    void pop(){
        if(top == -1){
            cout << "Stack underflow";
            return;
        }
        top--;
    }
    bool isEmpty(){
        return top == -1;
    }

};