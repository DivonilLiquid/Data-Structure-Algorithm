#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll f(ll x){
    return (x*(x-1))/2;
}
class graph{
    ll V;
    unordered_map<ll,list<ll> > Gp;
public:
    graph(ll x){
        V=x;
        for(ll i=0;i<V;i++){
            Gp[i];
        }
    }
    void addEdge(ll x,ll y){
        Gp[x].push_back(y);
        Gp[y].push_back(x);
    }
    ll dfs_helper(ll src,map<ll,bool> &visited){
        visited[src]=true;
        if(Gp[src].size()==0){
            return 1;
        }
        int x =1;
        for(auto i: Gp[src]){
            if(visited[i]==false){
                visited[i]=true;
                x = x+dfs_helper(i,visited);
            }
        }
        return x;
    }
    void dfs(ll src, vector<ll> &size){
        map<ll,bool>visited;
        for(auto i:Gp){
            visited[i.first]=false;
        }
        
        for(auto i:Gp){
            if(visited[i.first]==false){
                ll e = dfs_helper(i.first,visited);
                size.push_back(e);
            }
        }
        return ;
    }
    void print(){
        for(auto i: Gp){
            cout<<"Vertex "<<i.first<<" -> ";
            for(auto p : i.second){
                cout<<p<<", ";
            }
            cout<<endl;
        }
    }

};
int main() {
    ll n,p;
    cin>>n>>p;
    graph g(n);
    for(ll i=0;i<p;i++){
        ll x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    //g.print();
    vector<ll> size;
    g.dfs(0,size);
    ll res = f(n);
    for(ll i:size){
        res -= f(i);
    }
    cout<<res;
    return 0;
}
