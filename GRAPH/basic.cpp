#include<bits/stdc++.h>
using namespace std;


// adjacency matrix = (vxv) size of matrix 
// will be the no. of vertex cross vertex
// undirected unweighted graph


int main(){

    int vertex, edges;
    cout<<"Enter no. of vertex and edges : ";

    cin >> vertex >> edges;

    // for weighted 
    vector<vector<int>>AdjMat(vertex, vector<int>(vertex,0));

    int u,v, weight; // represting edge to edge connection

    for(int i=0; i<edges; i++){
        cin >> u >>v>> weight;
        AdjMat[u][v]=weight;
        AdjMat[v][u]=weight;
    }

    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}