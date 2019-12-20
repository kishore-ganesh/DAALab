#include <bits/stdc++.h>

using namespace std;

int DP[101][101][4];

string remove(string S1, int i)
{
    return S1.substr(0, i) + S1.substr(i + 1, S1.size() - i - 1);
}

string insert(string S1, int i, char c)
{
    return S1.insert(i, 1, c);
}

string change(string S1, int i, char c)
{
    S1[i] = c;
    return S1;
}

int editDistance(string S1, string S2, int i, int j, int op)
{
    if (i == S1.size() && j == S2.size())
    {
        return 0;
    }

    if(DP[i][j][op]!=-1){
        return DP[i][j][op];
    }
    // if(DP[i][j] != -1){
    //     return DP[i][j];
    // }
    if (i >= S1.size() && j < S2.size())
    {
        return DP[i][j][op] = 1 + min(editDistance(insert(S1, i,S2[j]),S2, i + 1, j + 1,0), editDistance(S1, remove(S2, j), i, j,1));
    }

    int mm = 1000;
    if(S1[i]==S2[j]){
        return DP[i][j][op] = editDistance(S1, S2, i+1, j+1, 2);
    }
    if (S1.size() < S2.size())
    {
        mm = editDistance(insert(S1, i,S2[j]), S2,i + 1, j + 1,0);
        mm = min(mm, editDistance(S1, remove(S2, j), i, j,1));
    }
    mm = min(mm, editDistance(change(S1, i, S2[j]), S2, i + 1, j + 1, 3));
    return DP[i][j][op] = mm + 1;
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
                DP[i][j][0] = -1;
                DP[i][j][1] = -1;
                DP[i][j][2] = -1;
                DP[i][j][3] = -1;
            }
        }
        int P, Q;
        cin >> P >> Q;
        string S1, S2;
        cin >> S1 >> S2;
        if (S1.size() > S2.size())
        {
            swap(S1, S2);
        }

        cout << editDistance(S1, S2,0, 0, 2) << endl;
    }
}