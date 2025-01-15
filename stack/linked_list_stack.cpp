#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char value) : data(value), next(nullptr) {}
};

class Linked_List_Stack{
    Node* top;
    public:
    Linked_List_Stack() : top(nullptr) {}

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop(){
        if (top == nullptr){
            cout << "Nothing to pop really";
            return;
        }
        Node* temp = top;
        char num = temp->data;
        top = top->next;
        delete temp;
        return num;
    }
    char peek(){
        if (top == nullptr){
            cout << "Empty";
             return;
        }
        char num = top->data;
        return num;
    }

    bool isPalindrome(string s){
       for (char ch: s){
        push(ch);
       } 
       for(char ch: s){
        if (ch != pop()){
            return false;
        }
       }
       return true;
    }
    string decimaltoBinary(int value){
        string temp = "";
        if (value == 0) return "0";
        while (value > 0){
            int rem = value%2;
            push(rem + '0');
            value = int(value/2);
        }
        while (top!= nullptr){
            temp+=pop();
        }
        return temp;
    }

    int precedence(char op){
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' ) return 2;
    }

    string infixtoPostfix(string s){
        string postfix = "";
        for (char ch : s){
            if (isalnum(ch)) postfix+=ch;
            else if (ch == '(') push(ch);
            else if(ch == ')') {
                while (peek() != '('){
                    postfix+= pop();
                }
                pop();
            }
            else {
                while(top!= nullptr && precedence(ch) < precedence(peek())){
                    postfix+=pop();
                }
                push(ch);
            }
        }
        while(top!=nullptr){
            postfix+= pop();
        }
        return postfix;
    }

    char evaluate_Postfix(string expression){
        for(char ch: expression){
            if(isdigit(ch)) push(ch);
            else{
                int a = pop();
                int b = pop();
                if(ch == '+') push(a+b);
                else if(ch == '-') push(a-b);
                else if(ch == '*') push(a*b);
                else if(ch == '/') push(int(a/b));
                else if(ch == '^') push(pow(a,b));
            }
        }
        return peek();
    }






};