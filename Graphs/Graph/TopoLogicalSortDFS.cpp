#include <bits/stdc++.h>
using namespace std;
void addEdge(map<string,list<string>> &adj,string &x,string &y){
    adj[x].push_back(y);
}
void dfs_helper(map<string,list<string>> &adj,map<string,bool> &mp,list<string> &ordering ,string node){
    mp[node]=true;
    for(auto nbr:adj[node]){
        if(!mp[nbr]){
            dfs_helper(adj,mp,ordering,nbr);
        }
    }
    //send that neigbour in linked list which doesn't have any child
    ordering.push_front(node);
}
void dfs(map<string,list<string>> &adj,int V){
    map<string,bool> mp;
    list<string> ordering;
    for(auto i: adj){
        mp[i.first]=false;
    }
    for(auto i:adj){
        if(!mp[i.first])
        dfs_helper(adj,mp,ordering,i.first);
    }
    for(auto l:ordering){
        cout<<l<<" ";
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    map<string,list<string>> adj;
    for(int i=0;i<e;i++){
        string x,y;
        cin>>x>>y;
        addEdge(adj,x,y);
    }
    dfs(adj,n);
}
