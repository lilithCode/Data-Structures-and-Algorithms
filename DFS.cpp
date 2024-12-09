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
    void dfsHelper(int node, vector<bool> &visited) {
        // Mark the current node as visited
        visited[node] = true;
        cout << node << " ";

        // Recur for all adjacent nodes
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }
     // DFS Function
    void dfs(int start) {
        vector<bool> visited(vertices, false); // Track visited nodes
        cout << "DFS Traversal starting from node " << start << ": ";
        dfsHelper(start, visited);
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
    g.dfs(0);

    return 0;
}
 