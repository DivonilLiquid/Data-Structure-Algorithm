#include <bits/stdc++.h>
using namespace std;
class graph{
    unordered_map<int, list<int> >m;
public:
    void addEdge(int x, int y){
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void bfs_helper(int src,map<int,bool> &mp){
        //cout<<src<<", ";
        mp[src]=true;
        for(auto i: m[src]){
            if(mp[i]==false){
                bfs_helper(i,mp);
            }
        }
    }
    void dfs(){
        map<int,bool> mp;
        for(auto i:m){
            mp[i.first] = false;
        }
        int cmp =0;
        for(auto i: mp){
            if(mp[i.first]==false){
                cout<<"Src "<<i.first<<endl;
                cmp++;
                bfs_helper(i.first,mp);
            }
        }
        cout<<"Number of components: "<<cmp;
    }

};
int main() {
    graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(6,5);
    g.addEdge(6,7);
    g.dfs();
}
