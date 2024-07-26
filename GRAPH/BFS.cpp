#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

void form_graph(vector<list<int>>& graph, int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void display(const vector<list<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto ele : graph[i]) {
            cout << ele << ", ";
        }
        cout << endl;
    }
}

void bfs(const vector<list<int>>& graph, vector<bool>& visited, int Node) {
    queue<int> q;
    visited[Node] = true;
    q.push(Node);

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        cout << frontNode << " ";   // we can also store in vector

        for (auto adj_node : graph[frontNode]) {

            if ( !visited[adj_node] ) {
                visited[adj_node] = true;
                q.push(adj_node);
            }
        }
    }
}


// if graph is disconnected
void bfs_traversal(const vector<list<int>>& graph) {
    int connectedComponent=0;
    vector<bool> visited(graph.size(), false);

    // if graph is disconnected
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            connectedComponent++;
            bfs(graph, visited, i);
        }
    }
    cout << endl;
    cout<<"no. of connected component: "<<connectedComponent;
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    vector<list<int>> graph(v);

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (src dest): " << endl;
    while (e--) {
        int src, dest;
        cin >> src >> dest;
        form_graph(graph, src, dest);
    }

    display(graph);

    cout << "BFS Traversal of the graph: ";
    bfs_traversal(graph);

    return 0;
}
