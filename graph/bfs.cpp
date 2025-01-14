#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int node, vector<vector<int>> &graph, vector<bool> &visited, queue<int> &q) {
    if (q.empty()) return;
    node = q.front();
    q.pop();
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
    BFS(node, graph, visited, q);
}

int main() {
    int nodes = 5;
    vector<vector<int>> graph(nodes);
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    vector<bool> visited(nodes, false);
    queue<int> q;

    cout << "BFS Traversal (Recursive): ";
    q.push(0);
    visited[0] = true;
    BFS(0, graph, visited, q);

    return 0;
}
