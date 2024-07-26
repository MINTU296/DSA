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

void DFS(vector<list<int>>& graph, int curr, int end, unordered_set<int>& visited, vector<int>& path, vector<vector<int>>& allPaths) {
    
    visited.insert(curr);
    path.push_back(curr);

    if (curr == end) {
        allPaths.push_back(path);
    } 
    else {
        for (auto neigb : graph[curr]) {
            if (visited.find(neigb) == visited.end()) { // node not visited
               
                DFS(graph, neigb, end, visited, path, allPaths);

            }
        }
    }

    path.pop_back();
    visited.erase(curr);
}

void findAllPaths(vector<list<int>>& graph, int src, int dest) {
    unordered_set<int> visited;
    vector<int> path;
    vector<vector<int>> allPaths;

    DFS(graph, src, dest, visited, path, allPaths);

    cout << "All paths from " << src << " to " << dest << ":" << endl;
    for (const auto& p : allPaths) {
        for (int node : p) {
            cout << node << " ";
        }
        cout << endl;
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

    int src, dest;
    cout << "Enter the source and destination to find all paths: ";
    cin >> src >> dest;

    findAllPaths(graph, src, dest);

    return 0;
}
