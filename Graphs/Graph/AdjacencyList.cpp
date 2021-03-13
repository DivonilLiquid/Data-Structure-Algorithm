#include <iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
        return;
    }
    void printList(){
        for(int i=0;i<V;i++){
            cout<<"Vertex: "<<i<<"-> ";
            for(int j: l[i]){
                cout<<j<<", ";
            }
            cout<<endl;
        }
        return;
    }
};
int main()
{
   Graph G(5);
   G.addEdge(0,1);
   G.addEdge(0,4);
   G.addEdge(4,3);
   G.addEdge(1,4);
   G.addEdge(1,2);
   G.addEdge(2,3);
   G.addEdge(1,3);
   G.printList();
   
   return 0;
}