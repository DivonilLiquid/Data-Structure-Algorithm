#include <bits/stdc++.h>
using namespace std;
void addEdge(map<string,list<string>> &adj,string &x,string &y){
    adj[x].push_back(y);
}
void bfs(map<string,list<string>> &adj){
    map<string,int>mp;
    for(auto i:adj){
        mp[i.first]=0;
    }
    for(auto i:adj){
        for(auto j:i.second){
            //cout<<"j are: "<<j<<endl;
            mp[j]++;
        }
    }
    queue<string> q;

    cout<<"InDegrees are: "<<endl;
    //0 indegree walle vertex ko sbse pehle queue mai insert kro
    //it's nothing but the concept of indegree
    for(auto i:mp){
        cout<<i.first<<" "<<mp[i.first]<<endl;
        if(mp[i.first]==0){
            q.push(i.first);
        }
    }
    list<string> ordering;
    while(!q.empty()){
        string curr = q.front();
        ordering.push_back(curr);
        q.pop();
        for(auto nbr: adj[curr]){
            mp[nbr]--;
            if(mp[nbr]==0){
                q.push(nbr);
            }
        }
    }
    for(auto i:ordering){
        cout<<i<<" ";
    }


    /*mp[node]=true;
    */
    return;
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
    bfs(adj);
}
