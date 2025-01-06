#include <iostream>
#include <vector>
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
};