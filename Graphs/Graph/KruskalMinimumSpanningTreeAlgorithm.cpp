#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
bool cmp(vector<int> &a,vector<int> &b){
    int x = a[2];
    int y = b[2];
    return x<y;
}
int find(int x){
    if(parent[x]==-1){
        return x;
    }
    return parent[x]=find(parent[x]);
}
bool uni(int x,int y,vector<int> &rank){
    int p = find(x);
    int q = find(y);
    if(p!=q){
        if(rank[p]>rank[q]){
            parent[q]=p;
            rank[p] += rank[q];
        }
        else{
            parent[p]=q;
            rank[q] += rank[p];
        }
        return true;
    }
    return false;
}
int main() {
    int v,e;
    cin>>v>>e;
    parent.resize(v+2);
    for(int i=0;i<v+2;i++){
        parent[i]=-1;
    }
    vector<int> rank;
    rank.resize(v+2);
    for(int i=0;i<v+2;i++){
        rank[i]=1;
    }
    vector<list<pair<int,int> > >adj(e+1);
    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].push_back(make_pair(v2,w));
        //if it's undirected graph
        //adj[v2].push_back(make_pair(v1,w));
    }
    //for(int i=0;i<=)
    vector<vector<int>> sorted;
    for(int i=0;i<=v;i++){
        for(auto j: adj[i]){
            vector<int> p;
            p.push_back(i);
            p.push_back(j.first);
            p.push_back(j.second);
            sorted.push_back(p);
        }
    }
    sort(sorted.begin(),sorted.end(),cmp);
    /*cout<<"sorted has "<<endl;
    for(int i=0;i<sorted.size();i++){
        cout<<sorted[i][0]<<" "<<sorted[i][1]<<" "<<sorted[i][2]<<endl;
    }*/
    int ans =0;
    for(int i=0;i!=sorted.size();i++){
        
        bool p = uni(sorted[i][0],sorted[i][1],rank);
        string q = (p==0?"false":"true");
        if(p){
            cout<<"for vertex "<<sorted[i][0]<<" and "<<sorted[i][1]<<" ans is "<<q<<" with value "<<sorted[i][2]<<endl;
        
            ans+=sorted[i][2];
        }
    }
    cout<<ans;
}
