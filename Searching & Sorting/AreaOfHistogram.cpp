#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; //since ,Height of each bar in histogram <= 10^9
ll AreaOfHistogram(ll *a, ll n){
	stack<ll> s;
	ll ans=0;
	for (int i = 0; i <= n; ++i)
	{
		if(s.empty()){
			s.push(i);
		}
		else{
			while(!s.empty() && a[s.top()]>a[i]){ 				//    	
	        	ll temp_ans=0;
				ll index=s.top();
				s.pop();
				if (s.empty())
				{
					temp_ans=a[index]*i;
				}
				else{
					temp_ans=a[index]*(i-s.top()-1);
				}
			ans=max(ans,temp_ans);
			}
			s.push(i);
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;

	ll*a=new ll[n+1]; //dynamically allocating array of size 
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i]; // entering height of array in array from [0,n-1]
	}
	/*5
	1 2 3 4 5
	now making a[5]=0 so that we can't get error while operating for a[4]
	*/
	a[n]=0;
	cout<<AreaOfHistogram(a,n)<<endl;
	return 0;
}