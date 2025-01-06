#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int value) : key(value) , left(nullptr) , right(nullptr) {}
};

class BinarySearchTree{
private:
    Node* root;
public:
    BinarySearchTree(): root(nullptr) {}

    void insert(int value){
        Node* newNode = new Node(value);
        if(!root){
           root = newNode;
           return; 
        }
        Node* curr = root;
        while(true){
            if(value < curr->key){
                if(!curr->left){
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
            }
            else{
                if(!curr->right){
                    curr->right= newNode;
                    break;
                }
                curr = curr->right;
            }
        } 
    }
    void deletebyCopy(int value){
        Node* curr = root;
        Node* parent;
        while(true){   // searching for the node to be deleted
            if(value > curr->key){
                if(!curr->right){
                    cout << "Value doesn't exist";  // incase we dont find it
                    return;
                }
                parent = curr;       // needed when connecting parent with the deceased node children i.e    1 2 3 connecting 1 and 3 , curr is 2
                curr = curr->right;
            }
            else if(value < curr->key) {
                if(!curr->left){
                    cout << "Value doesn't exist";
                    return;
            }
                parent = curr;
                curr = curr->left;
            }
            else{
                break;
            }
        }
        if(!curr->right && !curr->left){   // incase of leaf node
            if(curr == root){   // if the node to be deleted is root 
                root = nullptr;
            }
            else if(parent->left == curr){
                parent->left = nullptr;
            }
            else{
                parent->right= nullptr;
            }
            delete curr;
        }
        else if(!curr->right || !curr->left){
            Node* child = (curr->left) ? curr->left : curr->right ;
            if(curr = root){
                root = child;
            }
            if(parent->left == curr){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            delete curr; 
        }
        else{
            Node* temp = Min_Max(curr->right,false);             
            deletebyCopy(temp->key);
            curr->key = temp->key;
        }
    }

    Node* Min_Max(Node* node, bool value){
        if(!node){
            cout << "Nullptr";
            return;
        }
        if (value){
            while(node->right)
                {
                    node = node->right;
                }
            return node;
        }
        else{
            while(node->left)
                {
                    node = node->left;
                }
            return node;
        }
    }
    void deleteByMerge(int value, bool direction){
        Node* curr = root;
        Node* parent;
        while(true){
            if(curr->key < value){
                if(!curr->right){
                    cout<< "Value doesnt exist";
                    return;
                }
                parent = curr;
                curr = curr->right;
            }
            else if(curr->key > value) {
                if(!curr->left){
                    cout<< "Value doesnt exist";
                    return;
                }
                parent = curr;
                curr = curr->left;
            }
            else{
                break;
            }
        }
        if(!curr->left && !curr->right){
            if (curr == root){
                root = nullptr;
            }
            if(parent->left == curr){
                parent->left = nullptr;
            }
            else{
                parent->right = nullptr;
            }
            delete curr;
        }
        else if(!curr->right || !curr->left){
            Node* child = (curr->left) ? curr->left : curr->right;
            if(curr == root){
                root = child;
            }
            else if(curr == parent->left){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            delete curr;
        }
        else{
            if(direction){
                if(parent->left == curr){
                    parent->left = curr->right;
                }
                else{
                    parent->right = curr->right;
                }
                Node* temp = Min_Max(curr->right,false);
                temp->left = curr->left;
            }
            else{
                if(parent->left == curr){
                    parent->left = curr->left;
                }
                else{
                    parent->right = curr->left;
                }
                Node* test = Min_Max(curr->left,true);
                test->right = curr->right;
            }
        }

    }
    void preOrder(Node* node){
        if(node == nullptr){
            return;
        }
        cout << node->key <<  " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    void inOrder(Node* node){
        if(node == nullptr){
            return;
        }
        preOrder(node->left);
        cout << node->key <<  " ";
        preOrder(node->right);
    }
    void postOrder(Node* node){
        if(node == nullptr){
            return;
        }
        preOrder(node->left);
        preOrder(node->right);
        cout << node->key <<  " ";
    }
};