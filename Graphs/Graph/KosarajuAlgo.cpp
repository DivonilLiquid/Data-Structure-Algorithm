#include <bits/stdc++.h>
using namespace std;
void dfs_helper(vector<int> adj[],vector<int> &ordering,bool *visited,int node){
    visited[node]=true;
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            dfs_helper(adj,ordering,visited,nbr);
        }
    }
    ordering.push_back(node);

}
void dfs(vector<int> adj[],vector<int> &ordering,int V){
    bool *visited = new bool[V+1];
    for(int i=0;i<=V;i++){
        visited[i]=false;
    }
    for(int i=0;i<=V;i++){
        if(!visited[i]){
            dfs_helper(adj,ordering,visited,i);
        }
    }
    
    return;
}
void dfs_helper2(vector<int> adj[],bool *visited,int node){
    cout<<node<<", ";
    visited[node]=true;
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            dfs_helper2(adj,visited,nbr);
        }
    }
    return;
}
void dfs2(vector<int> adj[],vector<int> &ordering,int V){
    bool *visited = new bool[V+1];
    for(int i=0;i<=V;i++){
        visited[i]=false;
    }
    int cmp=0;
    for(int i=ordering.size()-1;i>=0;i--){
        if(!visited[ordering[i]]){
            cmp++;
            cout<<"Component "<<cmp<<" are: ";
            dfs_helper2(adj,visited,ordering[i]);
            cout<<endl;
        }
    }
    cout<<"Answer "<<cmp;
    return;
}
int main() {
    int v,e;
    cin>>v>>e;
    vector<int> adj[v+1];
    vector<int> Radj[v+1];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        Radj[y].push_back(x);
    }
    vector<int> ordering;
    dfs(adj,ordering,v);
    cout<<"order of importance -> ";
    for(auto i:ordering){
        cout<<i<<", ";
    }
    cout<<endl;
    dfs2(Radj,ordering,v);
}
