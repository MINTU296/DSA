#include<bits/stdc++.h>
using namespace std;

vector<list<int>>graph;

void form_graph(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void TopologicalSort(int v){

    vector<int> indegree(v,0);
    // calculating no. of indegree...
    for(int i=0; i<v; i++){
        for(auto neighbour : graph[i] ){
            indegree[neighbour]++;
        }  
    }

    queue<int>q;
    vector<bool>visited(v,false);

    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
            visited[i]=true;
        }
    }

    // Bfs.....
    while(!q.empty()){
        
        int frontNode=q.front();
        cout<<frontNode<<" ";
        q.pop();
        for(auto neighbour : graph[frontNode]){
            if(visited[frontNode]){  
                indegree[neighbour]--;
                // if in-degree become zero then we have to insert in qeue
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
                
            }
        }

    }

}

int main(){
    int v,e; 
    cout<<"Enter the no. of vertices and no. of edges: ";
    cin>>v>>e;

    graph.resize(v, list<int>());
    cout<<"Enter the src to destination: "<<endl;
    while(e--){
        int src, dest;
        cin>>src>>dest;
        form_graph(src,dest,false); // directed
    }
    cout<<endl;
    cout<<"Topological-sort answer:  ";
    TopologicalSort(v);
    return 0;
}