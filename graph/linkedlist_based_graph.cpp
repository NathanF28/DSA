#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {}
};

class Graph {
public:
    int V;
    Node** linked;

    Graph(int V) : V(V), linked(new Node*[V]) {
        for (int i = 0; i < V; i++) {
            linked[i] = nullptr;
        }
    }

    void addEdge(int u, int v) {
        Node* newNode = new Node(v);
        newNode->next = linked[u];
        linked[u] = newNode;

        newNode = new Node(u);
        newNode->next = linked[v];
        linked[v] = newNode;
    }

    void displayGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " is connected to: ";
            Node* temp = linked[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void DFSbyStack(int start) {
        bool* visited = new bool[V]{false};  // To keep track of visited nodes
        stack<int> s;

        // Start DFS from the given start node
        s.push(start);
        visited[start] = true;

        while (!s.empty()) {
            // Pop a vertex from the stack
            int node = s.top();
            s.pop();
            cout << node << " ";  // Print the visited node

            // Traverse the neighbors of the node
            Node* temp = linked[node];
            while (temp != nullptr) {
                int neighbor = temp->data;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
                temp = temp->next;
            }
        }
        cout << endl;
        delete[] visited;  // Clean up memory
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Graph adjacency list:" << endl;
    g.displayGraph();

    cout << "DFS traversal starting from vertex 0:" << endl;
    g.DFSbyStack(0);

    return 0;
}
