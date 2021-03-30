#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
 
#define int long long int

class DSU
{
	vector<int>parent;
public:
	DSU(int n){
		parent.resize(n);
		iota(parent.begin(), parent.end(),0);
	}
	int findSet(int x){
        if(parent[x]==x){
            return x;//returns that index which is not colored
        }
        //path compression technique
        return parent[x]=findSet(parent[x]);
    }
    void Get(int x,int y){
    	x = findSet(x);
    	y = findSet(y);
    	if(x!=y){
            //parent[x] & parent[y] contains that index which is rightmost of them
    		parent[x]=max(parent[x],parent[y]);
    		parent[y]=max(parent[x],parent[y]);
    	}
    }
	
};

int32_t main()
{
    /*
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	int n;
	cin>>n;
	DSU d(n+2);
	int q;
	cin>>q;
	
	int *l = new int[q];
	
	int *r = new int[q];
	
	int *c = new int[q];
	
	for (int i = 0; i < q; ++i)
	{
		cin>>l[i]>>r[i]>>c[i];
	}
	int res[n+2]={0};
	for (int i = q-1; i >=0 ; --i)
	{
		int index = d.findSet(l[i]);

		while(index<=r[i]){
			res[index]=c[i];
			d.Get(index,index+1);//
			index = d.findSet(index);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}







