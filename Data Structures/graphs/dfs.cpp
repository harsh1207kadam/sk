#include <iostream>
#include <vector>

using namespace std;


void DFS(int vertex, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[vertex] = true;  
    cout << vertex << " ";

    
    for (int i = 0; i < graph[vertex].size(); ++i) {
        int adjacentVertex = graph[vertex][i];
        if (!visited[adjacentVertex]) {
            DFS(adjacentVertex, graph, visited);
        }
    }
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    
    vector<vector<int>> graph(numVertices);


    int numEdges;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;

    
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }

    
    vector<bool> visited(numVertices, false);

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS Traversal: ";
    DFS(startVertex, graph, visited);
    cout << endl;

    return 0;
}
