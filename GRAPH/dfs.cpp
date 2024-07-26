#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

void form_graph(vector<list<int>>& graph, int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

bool DFS(vector<list<int>>& graph, int curr, int end, unordered_set<int>& visited) {
    if (curr == end) return true; // found the destination

    visited.insert(curr); // mark as visited the node
    for (auto neigb : graph[curr]) {
        if (visited.find(neigb) == visited.end()) { // node not visited
            bool result = DFS(graph, neigb, end, visited);
            if (result) return true;
        }
    }
    return false;
}

// function for checking path between two node present or not
bool anyPath(vector<list<int>>& graph, int src, int dest, unordered_set<int>& s) {
    return DFS(graph, src, dest, s);
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

int main() {
    unordered_set<int> s; // for storing visited nodes
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

    int src, dest;
    cout << "Enter the source and destination to find path: ";
    cin >> src >> dest;

    bool pathExists = anyPath(graph, src, dest, s);
    if (pathExists) {
        cout << "There is a path from " << src << " to " << dest << endl;
    } else {
        cout << "There is no path from " << src << " to " << dest << endl;
    }

    return 0;
}
