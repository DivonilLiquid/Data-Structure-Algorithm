#include <bits/stdc++.h>
using namespace std;
bool dfs_helper(bool *visited,vector<int> adj[],bool *stack,int V,int node){
    visited[node]=true;
    stack[node]=true;
    for(auto nbr:adj[node]){
        if(stack[nbr]==true){
            return true;
        }
        else if(!visited[nbr]){
            bool cycleFound = dfs_helper(visited,adj,stack,V,nbr);
            if (cycleFound){
                return true;
            }
        }
    }
    stack[node]=false;
    return false;
}
bool dfs(vector<int> adj[],int V, int node){
    bool *visited = new bool[V+1];
    bool *stack = new bool[V+1];
    for(int i=0;i<=V;i++){
        visited[i]=false;
        stack[i]=false;
    }
    return dfs_helper(visited,adj,stack,V,node);
}
int main() {
    int v,e;
    cin>>v>>e;
    vector<int> adj[v+1];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    string s= dfs(adj,v,0) == true ? "Cycle is present": "Cycle is not present";
    cout<<"In Given Directed Graph "<<s<<endl;

}
