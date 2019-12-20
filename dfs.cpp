#include<bits/stdc++.h>
using namespace std;

bool* visited;
void dfs(vector<vector<int> > graph, int i){
    if(!visited[i]){
        cout << i << endl;    
        visited[i] = true;
    }
    for(int j = 0; j < graph[i].size(); j++){
        if(!visited[graph[i][j]]){
            dfs(graph, graph[i][j]); 
        }
        
    }
} 

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int> > graph;
    visited = (bool*)malloc(V);
    for(int i = 0; i < V; i++){
        vector<int> k;
        graph.push_back(k);
    }
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    dfs(graph, 0);
}