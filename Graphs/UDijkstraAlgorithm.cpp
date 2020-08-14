//understanding dijkstra algorithm
#include <iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class Graph
{
	unordered_map<T,list<pair<T,int>>> m;
public:
	void addEdge(T u,T v, int d, bool bidirectional=true){
		//starts at u ends at v with distance d
		m[u].push_back(make_pair(v,d));
		if(bidirectional){
			m[v].push_back(make_pair(u,d));
		}
	}
	void print(){
		for (auto j:m){
			/* code */
			cout<<j.first<<"->";
			for(auto i : j.second){
				cout<<i.first<<" has "<<i.second<<" value "<<endl;
			}
			cout<<endl;
		}
	}
	//Implementing Dijkstra
	void dijkstra(T src){
		unordered_map<T,int> dist;
		//m is map in which all key member is initialized to INT MAX 
		for(auto j:m){
			dist[j.first]=INT_MAX;
		}
		// make a set which has city and distance in it
		set<pair<int,T>> s;
		// ascending order for first element
		//initialize source distance to zero
		dist[src]=0;   //T->src;int->0
		s.insert(make_pair(0,src));
		while(!s.empty()){
			//starting point
			auto p=*(s.begin());
			T node=p.second;
			int nodedist=p.first;
			s.erase(s.begin());

			for (auto child :m[node])
			{
				/* code */
				if(nodedist+child.second<dist[child.first]){
					T dest=child.first;
					auto f=s.find(make_pair(dist[dest],dest));
					if(f!=s.end()){
						s.erase(f);
					}
					dist[dest]=nodedist+child.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}
		for(auto d:dist){
			if(d.first!=src)
			cout<<d.second<<" ";
		}
	}

	
};
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		Graph <int> G;
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y,r;
			cin>>x>>y>>r;
			G.addEdge(x,y,r);
		}
		int s;
		cin>>s;
		G.dijkstra(s);
	}

	return 0;
}