#include<bits/stdc++.h>
using namespace std;

vector<int> ap;
vector<int> low;
vector<int> parent;
vector<int> dt;
bool* visited;
int t = 0;

void articulationPoints(vector<vector<int>> g, int i){
    // cout << visited[i] << endl;
    // cout << i << endl;
    dt[i] = t++;
    low[i] = dt[i];
    visited[i] = true;
    int children = 0;
    for(int j = 0; j < g[i].size(); j++){
        int v = g[i][j];
        if(!visited[v]){
            children++;
            parent[v] = i;
            articulationPoints(g, v);
            low[i] = min(low[i], low[v]);
            // cout << low[v] << endl;
            if(parent[i]==-1&&children>=2){
                ap[i] = 1;
            }
            else if(parent[i]!=-1&&low[v]>=dt[i]){
                ap[i] = 1;
            }
        }
        else{
            if(v!=parent[i]){
                low[i] = dt[v];
            }
        }
        // cout << "Children: "<< children << endl;
    }
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int> > g;
    visited = new bool[V];
    for(int i = 0; i < V; i++){
        ap.push_back(0);
        low.push_back(-1);
        parent.push_back(-1);
        dt.push_back(0);
        vector<int> k;
        g.push_back(k);
        visited[i] = false;
    }
    
    
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    articulationPoints(g, 0);
    for(int i = 0; i < V; i++){
        if(ap[i]==1){
            cout << "Articulation Point " << i << endl;
        }
    }

}