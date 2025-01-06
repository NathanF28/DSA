#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList(): head(nullptr) {}

    void insertFront(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if(!head) {
            head = newNode;
            return;
        }
        else{
            Node* curr = head;
            while (curr->next){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    void insertAt(int pos,int value){
        if (pos == 0) {
            insertFront(value);
            return;
        }
        Node* curr = head;
        Node* newNode = new Node(value);
        for (int i = 0; curr && i < pos;i++) {
            curr = curr->next;
        }
        if(curr) {
            newNode->next = curr->next;
            curr->next = newNode;
        }
        else {
            cout << "invalid index";
            delete newNode;
            }
    }
    void deleteFront(){
        if(!head) {
            cout << "Nothing to delete";
            return;
        }
        Node* temp = head; // to free the memory of the node to be deleted (could have used head = head->next but that wont't free head)
        head = temp->next;
        delete temp;
    }
    void deleteEnd(){
        if(!head) {
            cout << "Nothing to delete";
            return;
        }
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next->next) {
            curr = curr->next;
        }
        Node* toDelete = curr->next;
        curr->next = nullptr;
        delete toDelete;
    }
    void deleteAt(int pos){
        if(!head) {
            cout << "Nothing to delete";
            return;
        }
        if (pos == 0) {
            deleteFront();
            return;
        }
        Node* curr = head;
        for (int i = 1; curr && i < pos; i++) {
            curr = curr->next;
        }
        if (curr && curr->next){
            Node* toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
        }
        else{
            cout << "Invalid index";
            return;
        }
    }
    void reverse(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void display() {
        Node* curr = head;
        while(curr){
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "null\n";
    }
};
struct DoubleNode{
    int data;
    DoubleNode* prev;
    DoubleNode* next;
    DoubleNode(int value) : data(value) , next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList{
    DoubleNode* head;
    DoublyLinkedList() : head(nullptr) {}

    void insertFront(int value){
        DoubleNode* newNode = new DoubleNode(value);
        if(!head){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertEnd(int value) {
        DoubleNode* newNode = new DoubleNode(value);
        if(!head){
            head = newNode;
            return;
        }
        DoubleNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        } 
        curr->next = newNode;
        newNode->prev = curr;
    }
    void insertAt(int pos, int value) {
        DoubleNode* newNode = new DoubleNode(value);
        if(pos == 0){
            insertFront(value);
            return;
        }
        DoubleNode* curr = head;
        for(int i = 1; curr && i < pos;i++){
            curr = curr->next;
        }
        if(curr){
            if (!curr->next) { //we r basically inserting at the end like 4 -> null (after 4)
                insertEnd(value);
            }
            else {newNode->next = curr->next; // normal case
            curr->next->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
            }
        }
        else {
            delete newNode;
        }
    }
    void deleteFront(){
        if(!head) {
            cout << "Empty List";
            return;
        }
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }
        DoubleNode* temp = head;
        head = temp->next;
        temp->prev = nullptr;
        delete temp;
    }
    void deleteEnd(){
        if(!head) {
            cout << "Empty List";
            return;
        }
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }
        DoubleNode* curr = head;
        while (curr->next->next){
            curr = curr->next;
        }
        DoubleNode* toDelete = curr->next;
        curr->next = nullptr;
        delete toDelete; 
    }
    void deleteAt(int pos,int value){
        if (pos == 0) {
            deleteFront();
            return;
        }
        DoubleNode* curr = head;
        for (int i = 1; curr && i < pos; i++){
            curr = curr->next;
        }
        if(curr && curr->next){
            DoubleNode* toDelete = curr->next;
            curr->next = toDelete->next;
            if(toDelete->next) toDelete->next->prev = curr;
            delete toDelete;
        }
        else {
            cout << "Invalid index/n";
            return;
        }
    }
};
class SingleCircularLinkedList{
    Node* head;
    SingleCircularLinkedList() : head(nullptr) {}

    void insertFront(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;    
            newNode->next = head;
            return;
        }
        Node* curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        newNode->next = head;
        head = newNode;
        curr->next = head;
    }
    void insertEnd(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;    
            newNode->next = head;
            return;
        }
        Node* curr = head;
        while(curr->next != head){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = head;        
    }
    //Insertion at Position Jumped cause its similar to SinglyLinkedList , for edge cases we can call the respective funcs

    void deleteFront(){
        if(!head) {
            cout << "Nothing to delete";
            return;
        }
        if(!head->next){
            delete head;
            head = nullptr;
            return; 
        }
        Node* curr = head;
        while(curr->next != head){
            curr=curr->next;
        }
        Node* toDelete = head;
        head = head->next;
        curr->next = head;
        delete toDelete;
    }
    void deleteEnd(){
        if(!head){
            cout<< "nothing to delete";
            return;
        }
        if(!head->next){
            delete head;
            head = nullptr;
            return; 
        }
        Node* curr = head;
        while(curr->next->next != head){
            curr=curr->next;
        }
        Node* toDelete = curr->next;
        curr->next = head;
        delete toDelete;
    }
};

