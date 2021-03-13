#include <unordered_map>
#include<iostream>
#include<list>
using namespace std;
class graph{
    unordered_map<string,list<pair<string,int> > > mp;
public:
    void addEdge(string x,string y,bool bidr,int weight){
        mp[x].push_back(make_pair(y,weight));
        if(bidr){
            mp[y].push_back(make_pair(x,weight));
        }
    }
    void print(){
        for(auto city:mp){
            cout<<"City: "<<city.first<<" with neigbours = ";
            for(auto nbr:city.second){
                cout<<nbr.first<<" with cost "<<nbr.second<<", ";
            }
            cout<<endl;
        }
    }
};
int main()
{
   graph g;
   g.addEdge("A","B",true, 20);
   g.addEdge("B","D",true, 30);
   g.addEdge("A","C",true, 10);
   g.addEdge("C","D",true, 50);
   g.addEdge("A","D",false, 50);
   g.print();
   return 0;
}