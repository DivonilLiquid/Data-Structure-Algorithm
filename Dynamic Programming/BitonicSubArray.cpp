#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void BitonicSubArray(int *a, int n){
	int LeftRecord[n]={0};
	int RightRecord[n]={0};
	for (int i = 0; i < n; ++i)
	{
		LeftRecord[i]=1;
		RightRecord[i]=1;
	}
	int LeftMax=1,RightMax=1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			/* Small elements in left of a[i] */
			if(a[j]<a[i]){
				LeftRecord[i]=max(LeftRecord[j]+1,LeftRecord[i]);
			}

		}

		for (int j = n-1; j >i ; --j)
		{
			/* Small elements in right of a[i] */
			if(a[j]<a[i]){
				RightRecord[i]=max(RightRecord[j]+1,RightRecord[i]);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<LeftRecord[i]+RightRecord[i]-1<<" ";
	}
}
int main(int argc, char const *argv[])
{
	int n;//size of arr
	cin>>n;
	int *a = new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	BitonicSubArray(a,n);
	return 0;
}