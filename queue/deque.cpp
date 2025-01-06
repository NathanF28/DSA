#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int value): data(value) , next(nullptr) , prev(nullptr) {}
};

class Deque{
public:
    Node* head;
    Node* tail;
    Deque() : head(nullptr) , tail(nullptr) {}

    void pushEnd(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void pushFront(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = tail = newNode;
            return;
        }
        newNode->next =head;
        head->prev = newNode;
        head = newNode;
    }
    void popEnd(){
        if(!head){
            cout << "Empty Queue";
            return;
        }
        if(!head->next){
            delete head;
            head = tail = nullptr;
        }
        Node* toDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete toDelete;
    }
    void popFront(){
        if(!head){
            cout << "Empty Queue";
            return;
        }
        if(!head->next){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* toDelete = head;
        head = head->next;
        head->prev = nullptr;  // Handle established lines when bridge collapses
        delete toDelete;
    }
    int peekRear(){
        if(!head){
            cout << "Empty Queue";
            return -1 ;
        }
        return tail->data;
    }
    int peekFront(){
        if(!head){
            cout << "Empty Queue";
            return -1 ;
        }
        return head->data;
    }


};