#include <bits/stdc++.h>
using namespace std;
class graph{
    int V;
    map<int, list<int> > m;
public:
    void addEdge(int x, int y){
        m[x].push_back(y);
    }
    void SSSP(int x, int y){
        map<int,int> mp;
        for(int i=1;i<=100;i++){
            mp[i] = INT_MAX;
        }
        mp[x] = 0;
        queue<int> q;
        q.push(x);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i: m[node]){
                if(mp[i]==INT_MAX){
                    mp[i] = mp[node]+1;
                    q.push(i);
                }
            }
        }
        cout<<mp[y];
        return ;
    }
    void print(){
        for(auto i:m){
            cout<<"vertex is "<<i.first<<" ->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main() {
    int t;
    cin>>t;
    while(t--){
        graph g;
        int board[105];
        for(int i=1;i<=100;i++){
            board[i]=1;
        }
        int ladders;
        cin>>ladders;
        while(ladders--){
            int x,y;
            cin>>x>>y;
            board[x] = y-x;
        }
        int snakes;
        cin>>snakes;
        while(snakes--){
            int x,y;
            cin>>x>>y;
            board[x] = y-x;
        }
        for(int i=0;i<=100;i++){
            for(int j=1;j<=6;j++){
                int dice = i + j;
                dice += board[dice];
                if(dice<=100 && i<=99 && dice>0)
                g.addEdge(i+1,dice);
            }
        }
        g.addEdge(100,100);
        //g.print();
        g.SSSP(1,100);
        cout<<endl;
    }
}
