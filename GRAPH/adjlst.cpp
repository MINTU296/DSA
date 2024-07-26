#include <bits/stdc++.h>
using namespace std;

// vector<list<int>> graph; // for un weighted
// Function to form a graph by adding an edge from src to dest
// If bi_dir is true, an edge is also added from dest to src, making the edge bidirectional

// void form_graph(int src, int dest, bool bi_dir = true) {
//     graph[src].push_back(dest);
//     if (bi_dir) {
//         graph[dest].push_back(src);
//     }
// }

// weighted graph
vector<list <pair<int,int>> > graph;
void form_graph_weighted(int src, int dest, int weg, bool bi_dir = true) {

    graph[src].push_back({dest,weg});
    if (bi_dir) {
        graph[dest].push_back({src,weg});
    }
}
// Function to display the graph
void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto ele : graph[i]) {
            cout <<"("<<ele.first <<" "<<ele.second<< ") , ";
        }
        cout << endl;
    }
}
int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << endl;
    // Resize the graph to hold v vertices
    graph.resize(v, list<pair<int,int>>());
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    // Read all the edges
    while (e--) {
        int src, dest,weg;
        cin >> src >> dest>>weg;
        form_graph_weighted(src, dest,weg);
    }
    // Display the formed graph
    display();
}
