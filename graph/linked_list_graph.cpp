#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Linked_List_Graph{
public:
    Node** lists;
    int vertices;
    Linked_List_Graph(int value){
        vertices = value;
        lists = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            lists[i] = nullptr;  // Initialize each list to nullptr
        }
    }

    void addEdge(int u, int v){
        Node* newNode = new Node(v);
        newNode->next = lists[u];
        lists[u] = newNode;

        Node* newNode1 = new Node(u); 
        newNode1->next = lists[v];
        lists[v] = newNode1;
    }
    void printgraph(){
        for(int i = 0; i < vertices; i++){
            Node* temp = lists[i];
            while (temp){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    Linked_List_Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(3, 1);
    g.addEdge(3, 1);
    g.addEdge(3, 2);

    g.printgraph();
    return 0;


}