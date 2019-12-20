#include<bits/stdc++.h>
using namespace std;

bool* visited;
stack<int> s;
void topologicalSort(vector<vector<int> > g, int i){
    visited[i] = true;
    for(int j = 0; j < g[i].size(); j++){
        int v = g[i][j];
        if(!visited[v]){
            topologicalSort(g, v);
        }
    }
    s.push(i);
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int> > g;
    visited = new bool[V];
    for(int i = 0; i < V; i++){
       
       
        vector<int> k;
        g.push_back(k);
        visited[i] = false;
    }
    
    
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // g[v].push_back(u);
    }
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            topologicalSort(g, i);
        }
    }
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}