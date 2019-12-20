#include<bits/stdc++.h>

using namespace std;
int DP[101][101];

int editDistance(string A, string B, int i, int j){
    
    if(i==-1&&j==-1){
        return 0;
    }
    if(i==-1){
        return j+1;
    }
    if(j==-1){
        return i+1;
    }
    if(DP[i][j]!=-1){
        return DP[i][j];
    }
    if(A[i]==B[j]){
        return DP[i][j] = editDistance(A, B, i -1 , j - 1);
    }
    else{
        int mm = INT_MAX;
        mm = min(mm, editDistance(A, B,i, j - 1));
        mm = min(mm, editDistance(A, B, i - 1, j));
        mm = min(mm, editDistance(A, B, i - 1, j - 1));
        // cout << mm << endl;
        return DP[i][j] = mm + 1;
    }
}
int main()
{
    int T;
    cin >> T; 

    while (T--)
    {
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                DP[i][j] = -1;
                
            }
        }
        int P, Q;
        cin >> P >> Q;
        string S1, S2;
        cin >> S1 >> S2;

        cout << editDistance(S1, S2,P - 1, Q - 1) << endl;
    }
}