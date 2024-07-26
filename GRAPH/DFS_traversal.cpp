#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Function to add an edge to the graph
void form_graph(vector<list<int>>& graph, int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src); // For undirected graph, add edge in both directions
    }
}

// Function to display the graph's adjacency list
void display(const vector<list<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto ele : graph[i]) {
            cout << ele << ", ";
        }
        cout << endl;
    }
}

// Utility function for DFS traversal
void dfs(const vector<list<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true; // Mark the current vertex as visited
    cout << node << " ";  // Print the current vertex

    // Recur for all adjacent vertices
    for (auto adj_node : graph[node]) {
        if (!visited[adj_node]) {
            dfs(graph, visited, adj_node); // Recur for unvisited adjacent vertices
        }
    }
}

// Function to perform DFS traversal on the entire graph
void dfs_traversal(const vector<list<int>>& graph) {
    vector<bool> visited(graph.size(), false); // Initialize visited vector with false

    // Visit all vertices to cover disconnected graph components
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(graph, visited, i); // Perform DFS from the unvisited vertex
        }
    }
    cout << endl;
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v; // Input the number of vertices
    vector<list<int>> graph(v); // Create a graph with v vertices

    int e;
    cout << "Enter the number of edges: ";
    cin >> e; // Input the number of edges

    cout << "Enter the edges (src dest): " << endl;
    while (e--) {
        int src, dest;
        cin >> src >> dest; // Input each edge
        form_graph(graph, src, dest); // Add the edge to the graph
    }

    display(graph); // Display the graph

    cout << "DFS Traversal of the graph: ";
    dfs_traversal(graph); // Perform DFS traversal

    return 0;
}
