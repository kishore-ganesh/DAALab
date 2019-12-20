#include <bits/stdc++.h>
using namespace std;

int DP[101][101];
int lcs(string A, string B, int i, int j)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (DP[i][j] != -1)
    {
        return DP[i][j];
    }

    if (A[i] == B[j])
    {
        return DP[i][j] = 1 + lcs(A, B, i - 1, j - 1);
    }
    else
    {
        return DP[i][j] = max(lcs(A, B, i - 1, j), lcs(A, B, i, j - 1));
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
        int A, B;
        cin >> A >> B;
        string aString, bString;
        cin >> aString >> bString;
        lcs(aString, bString, A - 1, B - 1);
        cout << DP[A - 1][B - 1] << endl;
    }
}