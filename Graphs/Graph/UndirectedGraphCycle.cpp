#include <bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool cycleHelper(int node,bool *visited,int parent){
        visited[node]=true;
        for(auto nbr:l[node]){
            if(!visited[nbr]){
                bool nxt = cycleHelper(nbr,visited,node);
                if(nxt){
                    return true;
                }
            }
            else if(nbr != parent){
                return true;
            }
        }
        return false;
    }
    bool IsCycle(){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        return cycleHelper(0,visited,-1);
    }
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,0);
    string s = g.IsCycle()==1?"Present":"Not present";
    cout<<"Cycle is : "<<s;
}
