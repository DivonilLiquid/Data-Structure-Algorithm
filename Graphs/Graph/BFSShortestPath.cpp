#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
    int V;
    list<int> *l;
public:
    Graph(int v){
        this->V = v;
        this->l = new list<int>[V+1];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
        //return;
    }
    void sssp(int src){
        map<int,int>mp;
        for(int i=1;i<=V;i++){
            mp[i]=INT_MAX;
        }
        mp[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i: l[node]){
                if(mp[i]==INT_MAX){
                    mp[i] = mp[node] + 6;
                    q.push(i);
                }
            }
        }
        //cout<<"MAp"<<endl;
        for (int i = 1; i <= V; i++)
        {
            if (mp[i] == 0)
                continue;
            if (mp[i] == INT_MAX)
                cout<<-1<<" ";
            else    
            cout << mp[i] << " ";
        }
        cout<<endl;
    }
    void printList(){
        for(int i=1;i<=V;i++){
            cout<<"Vertex: "<<i<<"-> ";
            for(auto j: l[i]){
                cout<<j<<", ";
            }
            cout<<endl;
        }
        return;
    }
};
int main()
{
    int t,n,m;;
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        //cout<<"n is "<<n<<" and m is "<<m<<endl;
        Graph G(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            G.addEdge(x,y);
        }
        int x;
        cin>>x;
        G.sssp(x);
        //G.printList();
    }
   return 0;
}