#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n==1){
			cout<<"YES"<<endl;
		}
		else{
			//tiles can fill the desired boxes just check there diagonal elements
			int a[2][2][n];
			for(int i=0;i<n;i++){
				cin>>a[0][0][i]>>a[0][1][i]>>a[0][2][i]>>a[0][3][i];
			}
			int cnt=0;
			for (int i = 0; i < n; ++i)
			{
				if(a[0][0][i]==a[0][3][i] || a[0][1][i]==a[0][2][i]){
					cnt++;
				}
			}
			//cout<<endl<<"Value of count is "<<cnt<<endl;
			if(m%cnt==0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}