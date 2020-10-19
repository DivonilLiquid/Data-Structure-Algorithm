/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[2005][2005][8];
ll n,m,a[2005],b[2005];
ll f(ll i, ll j, ll k){
	if( i==n || j==m ){
		return 0;
	}
	if( dp[i][j][k] != -1 ){
		return dp[i][j][k];
	}
	ll res;
	if(a[i] == b[j]){
		res = 1 + f(i+1,j+1,k);
	}
	else{
		if(k > 0){
			res = 1 + f(i+1,j+1,k-1);
		}
		else{
			res = max (res,f(i,j+1,k));
			res = max (res,f(i+1,j,k));
		}
	}
	return dp[i][j][k]=res;
}
int main(){
	//n,m,k;
	memset( dp , -1 , sizeof(dp) );
	int k ;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<m; i++){
		cin >> b[i];
	}
	cout << f(0,0,k) << endl;
	return 0;
}