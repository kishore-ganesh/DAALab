#include<bits/stdc++.h>
using namespace std;

vector<vector<int > > adjacencyMatrix;
int source;
void printPoints(vector<int> points){
    for(int i = 0; i < points.size(); i++){
        cout << points[i] << "  ";
    }
    cout << endl;
}
int TSP(int p, vector<int> points){
    printPoints(points);
    if(points.size()==0){
        return adjacencyMatrix[p][source];
    }
    else{
        int mincost = INT_MAX;
        
        for(int i = 0; i < points.size(); i++){
            vector<int> newpoints = points;
            auto iter = find(newpoints.begin(), newpoints.end(), points[i]);
            newpoints.erase(iter);    
            mincost = min(mincost, adjacencyMatrix[p][points[i]]+TSP(points[i], newpoints));
        }
        return mincost;
    }
    
}
int main(){
    int V;
    cin >> V;
    for(int i = 0; i < V; i++){
         vector<int> k(V, 999);
         adjacencyMatrix.push_back(k);
    }
    int E;
    cin >> E;
    for(int i = 0; i < E; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adjacencyMatrix[u][v] = wt;
        // adjacencyMatrix[v][u] = wt;
    }
    cin >> source;
    vector<int> points;
    for(int i = 0; i < V; i++){
        if(i!=source){
            points.push_back(i);
        }
    }
    cout << TSP(source, points) << endl;
}