#include <bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list<pair<int,int>> l;
    public:
    graph(int x){
        this ->V = x;
    }
    void addEdge(int x,int y){
        l.push_back({x,y});
    }
    int findSet(int x, int *parent){
        if(parent[x]==-1){
            return x;
        }
        return findSet(parent[x],parent);
    }
    bool unionSet(int x,int y,int *parent){
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);
        if(s1 != s2){
            parent[s2]=s1;
            return false;
        }
        return true;
    }
    bool isCycle(){
        int *parent = new int[V+1];
        for(int i=0;i<=V;i++){
            parent[i]=-1;
        }
        for(auto i:l){
            int x = i.first;
            int y = i.second;
            bool sAns = unionSet(x,y,parent);
            //cout<<"sAns is "<<sAns<<" with x: "<<x<<" y: "<<y<<endl;
            if(sAns){
                return true;
            }
        }
        return false;
    }
};
int main() {
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<g.isCycle(); 
}
