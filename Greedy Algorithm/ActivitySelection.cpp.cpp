//Activity Selection
/*
You are given n activities (from 0 to n-1) with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> v1,pair<int,int> v2)
{
	return v1.second <v2.second;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			v.push_back(make_pair(a,b));
		}
		sort(v.begin(),v.end(),compare);
		int fin=v[0].second;
		int result=1;
		for(int i=1;i<n;i++)
		{
			if(v[i].first>=fin)
			{
				result++;
				fin=v[i].second;
			}

		}
		cout<<result<<endl;
	}
	return 0;
}
