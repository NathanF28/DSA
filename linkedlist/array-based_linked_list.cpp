#include <iostream>
using namespace std;

class ArrayList{
private:
    int listSize;
    int curr;
    int maxSize;
    int* listArray;
public:
    ArrayList(int size) {
        maxSize = size;
        listSize = 0;
        curr = 0;
        listArray = new int[maxSize];
    }
    ~ArrayList(){
        delete[] listArray;
    }

    void clear(){
        delete[] listArray;
        listSize = 0;
        curr = 0;
        listArray = new int[maxSize];
    }
    void setStart(){
        curr = 0;
    }
    void setEnd(){
        curr = listSize -1 ; 
    }
    void look_at_prev(){
        if (curr != 0) {
            curr-=1;
        }
    }
    void look_at_next(){
        if (curr < listSize) {
            curr+=1;
        }
    }
    int length(){
        return listSize;
    }
    bool set_at_position(int pos) { // bool is used to tell if operation is successfully performed or not
        if(pos >= 0 and pos < listSize) {
            curr = pos;
            return true;
        }
        return false;
    }
    int get_curr_value(){
        if(listSize > 0){
            return listArray[curr];      
        }
    }
    bool insert_at_curr(int value){ 
        if(listSize == maxSize){
            cout << "List is full";
            return false;
        }
        else {
            for(int i = listSize; i > curr; i--){ // easier to start from the back for size increment
                listArray[i] = listArray[i-1];
            } 
            listArray[curr] = value;
            listSize++;
            curr++;
            return true;
        }
    }
    bool insert_at_end(int value) {
         if(listSize == maxSize){
            cout << "List is full";
            return false;
        }
        else {
            listArray[listSize] = value;
            listSize++;
            curr = listSize-1;
            return true;
        }
    }
    bool remove_at_curr() {
        if (listSize == 0) {
            cout << "Empty List";
            return false;
        }
        else {
            for (int i= curr; i < listSize-1;i++){// easier to start from the front for size decrement 
                listArray[i] = listArray[i+1];
            }
            listSize--;
            return true;
        }
    } 


};