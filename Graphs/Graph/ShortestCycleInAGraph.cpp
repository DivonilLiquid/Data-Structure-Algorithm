#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
void print(vector<int> adj[],int V){
    for(int i=1;i<=V;i++){
        cout<<"Vertex "<<i<<"->";
        for(auto j: adj[i]){
            cout<<j<<", ";
        }
        cout<<endl;
    }
}
void ShortestCycle(vector<int> adj[],int V,int node,int &ans){
    int *distance = new int [V+1];
    for(int i=1;i<=V;i++){
        distance[i] = INT_MAX;
    }
    distance[node] = 0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i: adj[curr]){
            if(distance[i]==INT_MAX){
                //this node has not been visited
                distance[i] = distance[curr]+1;
                q.push(i);
            }
            else if(distance[i]>=distance[curr]){
                /*this has been visited so we will calculate, 
                minimum of distance of ith node + backedge
                */
                ans = min(ans,distance[i]+distance[curr]+1);
            }
        }
        
    }
}
int main() {
    int v,e;
    cin>>v>>e;
    vector<int> adj[v+1];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        addEdge(adj,x,y);
    }
    //print(adj,v);
    int ans = INT_MAX;
    for(int i=1;i<=v;i++){
        //cout<<"Answer is "<<ans<<endl;
        ShortestCycle(adj,v,i,ans);
    }
    string s = (ans==INT_MAX) ? "No Cycle" : to_string(ans);
    cout<<"Calculating shortest cycles gives: "<<s<<endl;
}
