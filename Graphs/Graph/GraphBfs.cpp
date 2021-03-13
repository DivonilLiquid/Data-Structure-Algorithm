#include <unordered_map>
#include <map>
#include<iostream>
#include<queue>
#include<list>
using namespace std;
class graph{
    unordered_map<string, list<string> > mp;
public:
    void addEdge(string x,string y){
        mp[x].push_back(y);
        //mp[y].push_back(x);
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
    void bfs(string src){
        map<string,bool>m;
        queue<string> q;
        q.push(src);
        m[src] = true;
        while(!q.empty()){
            string node = q.front();
            q.pop();
            cout<<"Neigbours of "<<node<<" are : ";
            for(string i:mp[node]){
                if(m[i]!=true){
                    cout<<i<<", ";
                    q.push(i);
                    m[i]==true;
                }
            }
            cout<<endl;
        }

    }
};
int main()
{
   graph g;
   g.addEdge("A","B");
   g.addEdge("B","D");
   g.addEdge("A","C");
   g.addEdge("C","D");
   g.addEdge("A","D");
   g.print();
   g.bfs("A");
   return 0;
}