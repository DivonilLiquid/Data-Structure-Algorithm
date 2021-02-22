#include <bits/stdc++.h>
using namespace std;
#define ll long long

void floyd(vector<vector<long long>> graph)
{
    vector<vector<long long>> dist(graph);
    for (int k = 0; k < 4; k++)
    {
        for (int u = 0; u < 4; u++)
        {
            for (int v = 0; v < 4; v++)
            {
                if (dist[u][k] + dist[k][v] < dist[u][v])
                {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << "From " << i + 1 << "->";
        for (int j = 0; j < 4; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<long long>> graph = {
        {0, INT_MAX, -2, INT_MAX},
        {4, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 2},
        {INT_MAX, -1, INT_MAX, 0},
    };
    floyd(graph);
    return 0;
}