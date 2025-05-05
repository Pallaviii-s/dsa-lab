/*C++ menu-driven program to implement Graph ADT with the implementation for Prim’s algorithm, Kruskal’s algorithm, and Dijkstra’s algorithm.*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjMatrix;  // Adjacency matrix for Prim's and Dijkstra's
    vector<pair<int, int>> *adjList;  // Adjacency list for Kruskal's
    int V;

    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adjMatrix[u][v] = adjMatrix[v][u] = w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // Prim's Algorithm
    void primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            for (int i = 0; i < V; i++) {
                if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }
            inMST[u] = true;
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        // Print the MST
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << endl;
        }
    }

    // Kruskal's Algorithm
    static bool compare(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        return a.second < b.second;
    }

    void kruskalMST() {
        vector<pair<pair<int, int>, int>> edges;
        for (int i = 0; i < V; i++) {
            for (auto& edge : adjList[i]) {
                if (i < edge.first) {
                    edges.push_back({{i, edge.first}, edge.second});
                }
            }
        }
        sort(edges.begin(), edges.end(), compare);

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int mstWeight = 0;
        cout << "Edge \tWeight\n";
        for (auto& edge : edges) {
            int u = edge.first.first, v = edge.first.second, weight = edge.second;
            int rootU = find(parent, u);
            int rootV = find(parent, v);

            if (rootU != rootV) {
                cout << u << " - " << v << "\t" << weight << endl;
                mstWeight += weight;
                unionSets(parent, rank, rootU, rootV);
            }
        }
    }

    int find(vector<int>& parent, int u) {
        if (parent[u] != u) {
            parent[u] = find(parent, parent[u]);
        }
        return parent[u];
    }

    void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    // Dijkstra's Algorithm
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& edge : adjList[u]) {
                int v = edge.first, weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Vertex \tDistance from source\n";
        for (int i = 0; i < V; i++) {
            cout << i << " \t" << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 9);

    cout << "Prim's MST:\n";
    g.primMST();

    cout << "\nKruskal's MST:\n";
    g.kruskalMST();

    cout << "\nDijkstra's Shortest Path from vertex 0:\n";
    g.dijkstra(0);

    return 0;
}
