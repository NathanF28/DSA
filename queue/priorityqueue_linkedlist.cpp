#include <iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node* next;
    Node(int value, int importance) : data(value), priority(importance) , next(nullptr) {}
};

class PriorityQueue{
public:
    Node* head;
    PriorityQueue() : head(nullptr) {}

    void push(int value, int priority){
        Node* newNode = new Node(value,priority);
        if(!head){
            head = newNode;
            return;
        }
        if(head->priority < priority){
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        while(curr->next && curr->next->priority > priority){
            curr= curr->next;
        }
        newNode = curr->next;
        curr->next = newNode;
    }

    int pop(){  //pop highest priority
        if(!head){
            cout << "Queue underflow";
            return -1;
        }
        int val = head->data;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return val;

    }
    int peek(){ 
        if(!head){
            cout << "Queue underflow";
            return -1;
        }
        return head->data;
    }
};