#include <unordered_map>
#include <map>
#include<iostream>
#include<queue>
#include<list>
#include<climits>
using namespace std;
class graph{
    unordered_map<string, list<string> > mp;
public:
    void addEdge(string x,string y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    void print(){
        for(auto city:mp){
            cout<<"City: "<<city.first<<" with neigbours = ";
            for(auto nbr:city.second){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
    void SSSP(string src){
        map<string,int>dist;
        for(auto np: mp){
            string node = np.first;
            cout<<node<<", ";
            dist[node] = INT_MAX;
        }
        queue<string> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            string node = q.front();
            q.pop();
            //cout<<"Neigbours of "<<node<<" are : ";
            for(string i:mp[node]){
                if(dist[i]==INT_MAX){
                    //cout<<i<<", ";
                    q.push(i);
                    //m[i]==true;
                    dist[i]=dist[node]+1;
                }
            }
           // cout<<endl;
        }
        for(auto np:mp){
            string node = np.first;
            int d = dist[node];
            cout<<"Node "<<node<<": is at dist from src "<<d<<endl;
        }
    }
};
int main()
{
   graph g;
   //g.addEdge("A","B");
   g.addEdge("B","D");
   g.addEdge("A","C");
   //g.addEdge("C","D");
   g.addEdge("A","D");
   g.print();
   g.SSSP("D");
   return 0;
}