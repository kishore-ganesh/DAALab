#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > board;
bool isSafe(int i, int j){
    for(int l = 0; l < board.size(); l++){
        if(board[l][j]==1||board[i][l]==1){
            return false;
        }
        if((l+i)< board.size() && (l+j) < board.size()){
            if(board[l+i][l+j]==1){
                return false;
            }
        }
        if((i-l)>=0 && (j-l) >=0){
            if(board[i-l][j-l]==1){
                return false;
            }
        }
    }
    return true;
}

bool NQueens(int K, int N){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(isSafe(i, j)){
                board[i][j] = 1;
                if(K<N){
                    if(NQueens(K+1, N)){
                        return true;
                    }
                    else{
                        board[i][j] = 0;
                    }
                    
                }
                else if(K==N){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        vector<int> k(K, 0);
        board.push_back(k);
    }
    cout << NQueens(1, K) << endl;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j]==1){
                cout << i << " " << j << endl;
            }
        }
    }
}