#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

// Function to add an edge to the graph
void addEdge(vector<vector<pii>>& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}


void primMST(vector<vector<pii>>& graph, int V) {
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> key(V, INT_MAX);

    
    vector<int> parent(V, -1);

    
    vector<bool> inMST(V, false);

    
    pq.push(make_pair(0, 0));
    key[0] = 0;

    while (!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();

        
        inMST[u] = true;

        
        for (auto neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            
            if (!inMST[v] && weight < key[v]) {
                
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pii>> graph(V);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(graph, u, v, weight);
    }

    primMST(graph, V);

    return 0;
}
