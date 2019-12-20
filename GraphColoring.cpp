#include<bits/stdc++.h>

using namespace std;
vector<int>  vertices;
vector<vector<int> > adjacencyMatrix;

bool isPossible(int i, int c){
    for(int j = 0; j < vertices.size(); j++){
        if(adjacencyMatrix[i][j]==1&&vertices[j]==c){
            return false;
        }
    }
    return true;
}

bool isColourable(int i, int M){
    for(int j = 0; j < M; j++){
        if(isPossible(i, j)){
            vertices[i] = j;
            if(i < vertices.size() -1 ){
                if(isColourable(i+1, M)){
                    return true;
                }
                vertices[i] = -1;
            }
            else if(i==vertices.size()-1){
                return true;
            }
            
        }
    }
    return false;
}

int main(){
    int V;
    cin >> V;
    for(int i = 0; i < V; i++){
        vector<int> k (V, 0);
        adjacencyMatrix.push_back(k);
        vertices.push_back(-1);
    }
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cin >> adjacencyMatrix[i][j];
        }
    }
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    int M;
    cin >> M;
    cout << isColourable(0, M);
}
