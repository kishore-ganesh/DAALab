#include <bits/stdc++.h>
using namespace std;

bool *visited;

void bfs(vector<vector<int>> graph)
{
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (!visited[p])
        {
            cout << p << endl;
            visited[p] = true;
            for (int j = 0; j < graph[p].size(); j++)
            {
                if (!visited[graph[p][j]])
                {
                    q.push(graph[p][j]);
                }
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph;
    visited = (bool *)malloc(V);
    for (int i = 0; i < V; i++)
    {
        vector<int> k(0);
        graph.push_back(k);
    }
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    bfs(graph);
}