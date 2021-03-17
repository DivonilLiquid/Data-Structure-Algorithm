#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class graph{
    ll V;
    list<pair<ll,ll> > *l;
public:
    graph(ll x){
        V = x;
        l = new list<pair<ll,ll>>[V+1];
    }
    void addEdge(ll x, ll y, ll z){
        l[x].push_back(make_pair(y,z));
        l[y].push_back(make_pair(x,z));
    }
    ll dfs_helper(ll node,map<ll,bool> &m,ll *cnt,ll &ans){
        m[node]=true;
        cnt[node] = 1;
        for(auto nbr : l[node]){
            int nbr_p = nbr.first;
            if(m[nbr_p]==false){
                cnt[node] += dfs_helper(nbr_p, m, cnt , ans);
                int nx = cnt[nbr_p];
                int ny = V-nx;
                ans += 2*min(nx,ny)*nbr.second;
            }
        }
        return cnt[node]; 
    }
    ll dfs(int src){
        map<ll,bool> m;
        ll *cnt = new ll[V+1];
        for(ll i=1;i<=V;i++){
            m[i]=false;
            cnt[i]=0;
        }
        ll ans = 0;
        dfs_helper(1,m,cnt,ans);
        return ans;
    }
    void print(){
        for(ll i=1;i<=V;i++){
            cout<<"Vertex "<<i<<" -> ";
            for(auto j:l[i]){
                cout<<"{"<<j.first<<","<<j.second<<"} ; ";
            }
            cout<<endl;
        }
    }
};
int main() {
    int t;
    cin>>t;
    int p =1;
    while(t--){
        ll n;
        cin>>n;
        graph g(n);
        for(int i=0;i<n-1;i++){
            int x,y,z;
            cin>>x>>y>>z;
            g.addEdge(x,y,z);
        }
        //g.print();
        cout<<"Case #"<<p<<": "<<g.dfs(1)<<endl;
    }
}
