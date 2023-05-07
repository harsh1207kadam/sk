#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& adjList, int startVertex) {
    queue<int> q;
    vector<bool> visited(adjList.size(), false);

    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        cout << currVertex << " ";

        for (int i = 0; i < adjList[currVertex].size(); i++) {
            int nextVertex = adjList[currVertex][i];
            if (!visited[nextVertex]) {
                q.push(nextVertex);
                visited[nextVertex] = true;
            }
        }
    }
    cout << endl;
}
int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adjList(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cout << "Enter the source and destination of edge " << i + 1 << ": ";
        cin >> src >> dest;

        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Undirected graph, so add edge in both directions
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

     bfs(adjList, startVertex);

     return 0;
}