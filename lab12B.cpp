/*C++ menu-driven program to implement Graph ADT with an adjacency list. */

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adjList;  // Adjacency list

public:
    Graph(int v) {
        V = v;
        adjList.resize(V);
    }

    void insertEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex!" << endl;
            return;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Assuming undirected graph
    }

    void deleteEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex!" << endl;
            return;
        }

        adjList[u].remove(v);
        adjList[v].remove(u);  // Assuming undirected graph
    }

    bool searchEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertex!" << endl;
            return false;
        }
        
        for (int neighbor : adjList[u]) {
            if (neighbor == v)
                return true;
        }
        return false;
    }

    void displayGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
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
