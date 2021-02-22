#include<bits/stdc++.h>
using namespace std;
vector<int > Bellman_Ford(int V, int src, vector<vector<int> > edges){
	vector<int> dist(V+1, INT_MAX);
	dist[src] =0;
	for (int i = 0; i < V-1; ++i)
	{
		for(auto edge : edges){
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if(dist[u]!=INT_MAX and dist[u]+wt<dist[v]){
				dist[v] = dist[u]+wt;
			}
		}
	}
	//negative cycle
	for(auto edge : edges ){
		int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u]!=INT_MAX and dist[u]+wt < dist[v]){
				cout<<"Negative weight cycle found";
				exit(0);
			}
	}
	return dist;
}
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<vector<int > > edges;
	for (int i = 0; i < m; ++i)
	{
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back( {u, v, wt} );
	}
	vector<int > distances = Bellman_Ford(n, 1, edges);
	for (int i = 1; i <= n; ++i)
	{
		cout << "Node " << i << " is at distance " << distances[i] << endl;
	}
	return 0;
}