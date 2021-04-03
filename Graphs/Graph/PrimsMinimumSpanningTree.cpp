#include <bits/stdc++.h>
using namespace std;
int PrimsMst(vector<pair<int,int> > l[],int e,int v){
    priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,1});//weight , index
    bool *visited = new bool[v+1]{0};
    int ans =0;
    while(!Q.empty()){
        auto best = Q.top();
        int weight = best.first;
        int to = best.second;
        Q.pop();
        if(visited[to]){
            continue;
        }
        //cout<<"Taking vertex "<<best.second<<" with weight "<<best.first<<endl;
        
        ans+=weight;
            visited[to]=true;
            for(auto i: l[to]){
                if(visited[i.first]==false){
                    Q.push({i.second,i.first});
                }
            }
    }
    return ans; 
}
int main() {
    int v,e;
    cin>>v>>e;//vertex and edges
    vector<pair<int,int> > l[(v+1)];
    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        l[v1].push_back(make_pair(v2,w));
        l[v2].push_back(make_pair(v1,w));
    }
    int x = PrimsMst(l,e,v);
    cout<<x<<endl;
}
