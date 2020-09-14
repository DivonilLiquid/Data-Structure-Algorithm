#include <iostream>
#include <cstring>
using namespace std;
int PossiblePalindrome(string s){
	int n=s.length();
	bool dp[n][n]={0};
	for (int i = 0; i < n; ++i)
	{
		dp[i][i]=true;
	}

	for (int i = 0; i <n-1 ; ++i)
	{
		if(s[i]==s[i+1]){
			dp[i][i+1]=true;
		}
	}

	for (int i = 2; i <n ; ++i)
	{
		int j=0,k=i;
		while(k<n){
			if(s[j]==s[k] && dp[j+1][k-1]){
				dp[j][k]=true;
			}
			else{
				dp[j][k]=false;
			}
			j++;k++;
		}
	}
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(dp[i][j])
				cnt++;
		}
	}
	return cnt;
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<PossiblePalindrome(s)<<endl;
	return 0;
}