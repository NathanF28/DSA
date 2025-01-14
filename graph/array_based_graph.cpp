#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> Lists;
public:
    Graph(int value){
        vertices = value;
        adjMatrix.resize(vertices,vector<int>(vertices,0));
        Lists.resize(vertices);
    }

    void addEdge(int u, int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        Lists[u].push_back(v);
        Lists[v].push_back(u); 
    }

    void displayMatrix(){
        for(int i = 0; i< vertices;i++){
            for(int j=0; j < vertices; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void displayLists(){
        for(int i = 0; i <vertices;i++){
            cout << i << ":" << " ";
            for(int j : Lists[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void DFS_start(int value){
        vector<bool> visited(vertices,false);
        DFS(value,visited);
    }
    void DFS(int value,vector<bool>& visited){
        visited[value] = true;
        for(int neighbor : Lists[value]){
            if(!visited[neighbor]){
                DFS(neighbor,visited);
            }
        }
    }
    void DFS_Iterative(int value){
        vector<bool> visited(vertices, false);
        stack<int> s;
        s.push(value);
        while (!s.empty()){
             int top = s.top();
            s.pop();
            if(!visited[top]){
                visited[top] = true;            
            for(int neighbor: Lists[top]){
                if(!visited[neighbor]){
                    s.push(neighbor);
                }
            }
            }
        cout << endl;
        }

    }
    void BFS(int value){
        vector<int> visited(vertices,false);
        queue<int> q;
        q.push(value);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            if(!visited[value])
            {                            
            visited[front] == true;
            for(int neighbor : Lists[front])
            {
                if(!visited[neighbor]){
                    q.push(neighbor);
                }
            }
            }


        }
    }
};