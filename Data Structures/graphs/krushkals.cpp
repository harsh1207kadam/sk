#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};


class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};


bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}


vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
    
    sort(edges.begin(), edges.end(), compareEdges);

    
    DSU dsu(n);

    
    vector<Edge> mst;

    
    for (Edge e : edges) {
        int src = e.src, dest = e.dest, weight = e.weight;
        
        if (dsu.find(src) != dsu.find(dest)) {
            mst.push_back(e);
            dsu.merge(src, dest);
        }
    }

    return mst;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges;
    cout << "Enter edges in the format <source> <destination> <weight>:" << endl;
    for (int i = 0; i < m; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back(Edge(src, dest, weight));
    }

    vector<Edge> mst = kruskalMST(n, edges);

    cout << "Minimum Spanning Tree:" << endl;
    for (Edge e : mst) {
        cout << e.src << " - " << e.dest << " : " << e.weight << endl;
    }

    return 0;
}
