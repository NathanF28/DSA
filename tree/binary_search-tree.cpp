#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BSTree{
    Node* root;
public:
    BSTree() : root(nullptr) {}

    void insert(int value){
        Node* newNode = new Node(value);
        if(!root){
            root = newNode;
            return;
        }
        Node* curr = root;
        while(true){
            if(value > curr->data){
                if(!curr->right){
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
            }
            else if(value < curr->data){
                if(!curr->left){
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
            }
            else{
                cout << "Element already exists";
                break;
            }
        }
    }
    Node* insert_recursion(Node* node, int value){
        if(!node){
            return new Node(value);
        }
        if(value > node->data){
            node->right = insert_recursion(node->right,value);
        }
        else{
            node->left = insert_recursion(node->left,value);
        }
        return node;
    }
    Node* search(int value){
        Node* curr = root;
        while(curr){
            if(value == curr->data)
                return curr;
            else if(value > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }  
        return nullptr;
    }

    void deletebyCopy(int value){
        Node* curr = root;
        if(!root){
            cout << "empty";
            return;
        }
        Node* parent;
        while(curr){
            if(value == curr->data){
                break;
            }
            else if(value > curr->data){
                parent = curr;
                curr = curr->right;
            }
            else{
                parent = curr;
                curr = curr->left;
            }
        }
        if(!curr){                        // Node with value doesn't exist
            cout << "Element not found";
            return;
        }
        if(!curr->left && !curr->right){  // Node has one child
            if(!parent){
                root = nullptr;
            }
            else if(parent->left == curr){
                parent->left = nullptr;
            }
            else{
                parent->right = nullptr;
            }
            delete curr;
        }
        else if(!curr->left || !curr->right){
            Node* child = curr->left ? curr->left : curr->right;
            if(!parent){
                root = child;
            }
            else if(parent->left == curr){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            delete curr;
        }
        else{
            int temp = Max_Min(curr->right,true)->data;
            deletebyCopy(temp);
            curr->data = temp; 

        }     
    }
    Node* Max_Min(Node* node, bool left){
        if(!node){
            cout << "empty";
            return nullptr;
        }
        if(left){
            while(node->left){
            node = node->left;
        }
        }
        else{
            while (node->right){
            node = node->right;
        }
        }
        return node;
    }
    void deletebyMerge(int value, bool direction){
        Node* curr = root;
        if(!root){
            cout << "empty";
            return;
        }
        Node* parent;
        while(curr){
            if(value == curr->data){
                break;
            }
            else if(value > curr->data){
                parent = curr;
                curr = curr->right;
            }
            else{
                parent = curr;
                curr = curr->left;
            }
        }
        if(!curr){                        // Node with value doesn't exist
            cout << "Element not found";
            return;
        }
        if(!curr->left && !curr->right){  // Node has one child
            if(!parent){
                root = nullptr;
            }
            else if(parent->left == curr){
                parent->left = nullptr;
            }
            else{
                parent->right = nullptr;
            }
            delete curr;
        }
        else if(!curr->left || !curr->right){
            Node* child = curr->left ? curr->left : curr->right;
            if(!parent){
                root = child;
            }
            else if(parent->left == curr){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            delete curr;
        }
        else{
            if(direction){
                if(!parent){
                    parent = curr->right;
                    root = parent; // add this
                }
                else{
                    if(parent->left == curr)
                        parent->left = curr->right;
                    else
                        parent->right = curr->right;
                }
                Node* node1 = Max_Min(curr->right,true);
                node1->left = curr->left;
                delete curr;
            }
            else{
                if(!parent){
                    parent = curr->left;
                    root = parent; // add this
                }
                else{
                    if(parent->left == curr)
                        parent->left = curr->left;
                    else
                        parent->right = curr->left;
                }
                Node* node2 = Max_Min(curr->left,false);
                node2->right = curr->right;
                delete curr;
            }
        }     
    }
    void inOrderTraversal(Node* node){
        if(!node){
            return;
        }
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
    void preOrderTraversal(Node* node){
        if(!node){
            return;
        }
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    void postOrderTraversal(Node* node){
        if(!node){
            return;
        }
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
};