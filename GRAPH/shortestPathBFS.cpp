#include <bits/stdc++.h>
using namespace std;

// Function to form the graph by adding edges
void Form_Graph(vector<list<int>>& graph, int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void shortestPath(vector<list<int>>& graph, int src, vector<int>& dist, vector<bool>& visited) {
    queue<int> q;
    dist[src] = 0;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        // bfs traversal output
        cout<<curr<<" ";
        q.pop();

        for (auto neighbour : graph[curr]) {
            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
}

// Function to display the graph
void Display(const vector<list<int>>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (auto node : graph[i]) {
            cout << node << " , ";
        }
        cout << endl;
    }
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    // Initialize the graph with 'v' vertices
    vector<list<int>> graph(v);

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    // Read edges
    cout << "Enter the edges (src dest): " << endl;
    for (int i = 0; i < e; i++) {
        int src, dest;
        cin >> src >> dest;

        // Check if the vertices are within the valid range
        if (src >= v || dest >= v || src < 0 || dest < 0) {
            cout << "Invalid edge! Vertices should be between 0 and " << v - 1 << endl;
            i--; // decrement i to ask for the edge again
            continue;
        }

        Form_Graph(graph, src, dest);
    }

    // Display the graph
    Display(graph);

    cout << endl;
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);
    int src;
    cout << "Enter the src and dest: ";
    cin >> src;
    shortestPath(graph, src, dist, visited);
    cout<<endl;
    for (int i = 0; i < v; i++) {
        cout << "Vertex: " << i << " Distance: " << dist[i] << " Visited: " << visited[i] << endl;
    }

    return 0;
}
