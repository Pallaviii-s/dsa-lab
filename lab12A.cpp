/* C++ menu-driven program to implement Graph ADT with an adjacency matrix.*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adjMatrix;  // Adjacency matrix

public:
    Graph(int v) {
        V = v;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void insertEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex!" << endl;
            return;
        }
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Assuming it's an undirected graph
    }

    void deleteEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex!" << endl;
            return;
        }
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;  // Assuming it's an undirected graph
    }

    bool searchEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex!" << endl;
            return false;
        }
        return adjMatrix[u][v] == 1;
    }

    void displayGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, choice, u, v;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    
    Graph g(vertices);
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert edge\n";
        cout << "2. Delete edge\n";
        cout << "3. Search edge\n";
        cout << "4. Display graph\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter vertices (u v): ";
                cin >> u >> v;
                g.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter vertices (u v): ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter vertices (u v): ";
                cin >> u >> v;
                if (g.searchEdge(u, v))
                    cout << "Edge exists between " << u << " and " << v << endl;
                else
                    cout << "Edge does not exist between " << u << " and " << v << endl;
                break;
            case 4:
                g.displayGraph();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);
    
    return 0;
}
