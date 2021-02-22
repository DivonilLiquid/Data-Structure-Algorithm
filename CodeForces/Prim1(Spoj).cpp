#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> primes;
const int N = 100005;
ll p[N]={};
//have made sieve
void seive(){
	for(ll i=2;i<=N;i++){
		if(p[i]==0){
			primes.push_back(i);
			for(ll j=i*i;j<=N;j+=i){
				p[j]=1;
			}
		}
	}
}
int main() {
	// your code goes here
	seive();
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>m>>n;
		bool segment[n-m+1];
		//representation of segment variable
		for(int i=0;i<n-m+1;i++){
			segment[i]=0;
		}
		
		for(auto x: primes){
			if(x*x>=n){
				break;//to break loop
			}
			int start = (m/x)*x;
			if(x>=m && x<=n){
				start = 2*x;//overlapping case
			}
			for(int i=start;i<=n;i+=x){//making indexes of all elements which are divisible by x equal to 1
				segment[i-m]=1;
			}
		}
		for(int i=m;i<=n;i++){
			if(segment[i-m]==0 && i!=1){
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}








