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
bool coloring_helper(vector<int>adj[],int *visited, int node,int color,int parent){
    visited[node]=color;         // 0-> not visited, 1 & 2-> visited and colored
    for(auto nbr: adj[node]){
        if(visited[nbr]==0){//if any neighbour is not visited
            bool sprob = coloring_helper(adj,visited,nbr,3-color,node);
            return sprob;
        }
        else if(visited[nbr]==color and nbr!=parent){//neighbour is visited and not equal to parent
            return false;
        }
    }
    return true;
}
void coloring(vector<int> adj[], int V){
    int *visited = new int[V+1]{0};
    bool ans = coloring_helper(adj,visited,1,1,-1);
    for(int i=1;i<=V;i++){
        cout<<i<<" "<<visited[i]<<endl;
    }
    cout<<"Bipartite is "<<ans;
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
    coloring(adj,v);
    //print(adj,v);
    
}
