#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value) , next(nullptr) {}
};

class LLQueue{
    Node* head;
    LLQueue() : head(nullptr) {}

    void enqueue(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }
        Node* curr = head;
        while(curr->next){
            curr = curr->next;
        }        
        curr->next = newNode;
    }
    int dequeue(){
        if(!head){
            cout << "Queue Underflow";
            return -1;
        }
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }
        Node* toDelete = head;
        int temp = toDelete->data;
        head = head->next;
        delete toDelete;
        return temp;
    }
    int peek(){
        if(!head){
            cout << "Queue Empty";
            return -1 ;
        }
        int temp = head->data;
        return temp;
    }
    
};

