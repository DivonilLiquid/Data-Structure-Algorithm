/*
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains N denoting the size of the array. The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= Ai <= 106

Examples:
Input:
2
4
5 3 7 10
4
8 15 3 7
Output:
15
22

Explanation:
Testcase1: The user collects maximum value as 15(10 + 5)
Testcase2: The user collects maximum value as 22(7 + 15)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int OptimalStrategy(int *a,int n){
	int dp[n][n]={0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(i>j){
				dp[i][j]=0;
			}
			else if(i==j){
				dp[i][j]=a[i];
			}
		}
	}
	int i=0,j=1;
	while(i<n && j<n){
		int r=i;
		int c=j;
		while(i<n && j<n){
			dp[i][j]=max(a[j]+min(dp[i][j-2],dp[i+1][j-1]),a[i]+min(dp[i+1][j-1],dp[i+2][j]));
			i++;j++;
		}
		i=0;
		j=c+1;
	}
/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	return dp[0][n-1];
}
int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll *a=new ll[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<OptimalStrategy(a,n)<<endl;
	}
	return 0;
}