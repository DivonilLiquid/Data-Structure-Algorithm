/* INPUT 
4 6
1 2 1
1 3 2
1 4 2
2 4 3
2 3 2
3 4 3
*/
/*OUTPUT
0 1 1
0 2 2
0 3 2
5
*/
#include<bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int>par;
    void init(int n){
        par.resize(n);
        for(int i=0 ; i<n ; i++){
            par[i] = i;
        }
    }
    int get_super_parent(int x){
        if(x == par[x]) return x;
        else return par[x] = get_super_parent(par[x]);
    }
    void unite(int x , int y){
        int super_parent_x = get_super_parent(x);
        int super_parent_y = get_super_parent(y);
        if(super_parent_x != super_parent_y){
            par[super_parent_x] = super_parent_y;
        }
    }
};
int main(){
    int n , m;
    cin>>n>>m;
    dsu d;
    vector<vector<int>> edges(m);
    for(int i=0 ; i<m ; i++){
        int x, y,  w;
        cin>>x>>y>>w;
        x-- ; y--;
        edges[i] = {w , x , y};
    }
    sort(edges.begin() , edges.end());
    d.init(n);
    int ans = 0;
    for(int i=0 ; i<m ; i++){
        int w = edges[i][0];
        int x = edges[i][1];
        int y = edges[i][2];
        //cout<<w<<" "<<x<<" "<<y<<endl;
        if(d.get_super_parent(x) != d.get_super_parent(y)){
            d.unite(x , y);
            cout<<x<<" "<<y<<" "<<w<<endl;
            ans += w;
        }
    }
    cout<<ans<<endl;
    return 0;
}