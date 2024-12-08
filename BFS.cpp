#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Graph class
class Graph {
private:
    int vertices;                   // Number of vertices
    vector<vector<int>> adjList;    // Adjacency list

public:
    // Constructor
    Graph(int v) : vertices(v), adjList(v) {}

    // Function to add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);    // Add v to u's list
        adjList[v].push_back(u);    // Add u to v's list (for undirected graph)
    }

    // BFS function
    void BFS(int start) {
        vector<bool> visited(vertices, false); // To keep track of visited nodes
        queue<int> q;                          // Queue for BFS

        visited[start] = true; // Mark the start node as visited
        q.push(start);         // Enqueue the start node

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front(); // Get the front node in the queue
            q.pop();              // Dequeue it
            cout << node << " ";  // Print the current node

            // Explore all unvisited neighbors of the current node
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark neighbor as visited
                    q.push(neighbor);         // Enqueue neighbor
                }
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform BFS starting from node 0
    g.BFS(0);

    return 0;
}
