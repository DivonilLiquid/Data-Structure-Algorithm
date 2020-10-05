#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		if(n==1 || n==2){
			cout<<"1"<<endl;
		}
		else{
			n=n-2;
			int cnt=1;
			if(n%x!=0){
				cnt++;
			}
			cnt+=(n/x);
			cout<<cnt<<endl;		
		}
	}
	return 0;
}