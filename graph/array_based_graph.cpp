#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> List; 

    Graph(int value){
        vertices = value;
        adjMatrix.resize(vertices,vector<int>(vertices,0));
        List.resize(vertices);
    }

    void addEdge(int u, int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        List[u].push_back(v);
        List[v].push_back(u);
    }

    void displayMatrix(){
        for (int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices;j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void displayList(){
        for (int i = 0; i < vertices; i++){
            for(int j = 0; j < List[i].size();j++){
                cout << i << " : " << List[i][j] << " ";
            }
            cout << endl;
        }
    }
    void DFS_start(int value){
        vector<bool> visited(vertices,false);
        DFS(value,visited);
    }
    void DFS(int value, vector<bool>& visited){
        visited[value] = true;
        cout << value << " ";

        for(int neighbor: List[value]){
            if(!visited[neighbor]){
                DFS(neighbor,visited);
            }
        } 

    }
    void BFS(int start){
        vector<bool> visited(vertices,false);
        queue<int> q;

        visited[start] = true;
        while(q.size() > 0){
            if (visited[start]){
                cout << q.front() << " ";
                q.pop(); 
                for(int neighbor : List[start]){
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }

            }
        }
    }
};