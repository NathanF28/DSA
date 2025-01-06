#include <iostream>
using namespace std;

struct Data{
    int value;
    int priority;
    Data() : value(0) , priority(0) {}
    Data(int v, int p) : value(v) , priority(p) {}
};

class PriorityArray{
private:
    Data* arr;
    int size;
    int cap;

public:
    PriorityArray(int num){
        cap = num;
        size = 0;
        arr = new Data[cap];
    }
    void push(int value, int priority){
        Data* newData = new Data(value,priority);
        if(size == cap){
            cout << "Queue is full";
            return;
        }
        int pos;
        for(int i = size-1; i>-1;i--){
            pos = i;
            if(priority <= arr[i].priority){
                break;
            }
            else{
                arr[i+1] = arr[i];
            }
        }
        arr[pos+1] = *newData;
        size++;
    }
    int pop(){
        if (size == 0){
            cout << "Queue Underflow";
            return -1;
        }
        int temp = arr[0].value;
        for(int i = 0; i < size-1;i++){
            arr[i] = arr[i+1];
        }
        size--;
        return(temp);
    }
    int peek(){
        if (size == 0){
            cout << "Queue Underflow";
            return -1;
        }
        int temp = arr[0].value;
        return temp; 
    }
        
    

};