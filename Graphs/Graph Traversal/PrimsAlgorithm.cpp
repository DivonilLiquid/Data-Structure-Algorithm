#include <bits/stdc++.h>
using namespace std;
#define ll long long

class graph
{
    int v;
    list<pair<int, int>> *l;

public:
    graph(int v)
    {
        this->v = v;
        l = new list<pair<int, int>>[v+1];   
    }
    void addedge(int x, int y, int w)
    {
        l[x].push_back(make_pair(y, w));
        l[y].push_back(make_pair(x, w));   
    }
    int primsmsp(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
        h.push({0, src});
        int cost = 0;
        int visited[v + 1];
        for (int i = 0; i <= v; i++)
        {
            visited[i] = 0;
        }
      
        while (!h.empty())
        {
            auto best = h.top();
            h.pop();
            if (!visited[best.second])
            {
                cost += best.first;

               
                visited[best.second] = 1;
                for (auto p : l[best.second])
                {
                    if (!visited[p.first])                     
                    {
                        h.push(make_pair(p.second,p.first));   
                    }
                }
            }
        }
        return cost;
    }
};

int main()
{
    graph g(4);
    // input 1
    g.addedge(1, 2, 1);
    g.addedge(1, 3, 2);
    g.addedge(1, 4, 2);
    g.addedge(2, 3, 2);
    g.addedge(2, 4, 3);
    g.addedge(3, 4, 3);
    cout << g.primsmsp(1);   

    return 0;
}