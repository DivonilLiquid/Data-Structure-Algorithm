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
	cout<<"How many test cases do you want to run: ";
	int t;
	cin>>t;
	while(t--){
		int n;
		cout<<"Enter number of activities taking place: ";
		cin>>n;
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter starting & ending time of activity "<<i+1<<": ";
			int a,b;
			cin>>a>>b;
			v.push_back(make_pair(a,b));
		}
		sort(v.begin(),v.end(),compare);
		int fin=v[0].second;
		int result=1;
		vector<pair<int,int>> ans;
		ans.push_back({v[0].first,v[0].second});
		for(int i=1;i<n;i++)
		{
			if(v[i].first>=fin)
			{
				result++;
				fin=v[i].second;
				ans.push_back({v[i].first,v[i].second});
			}

		}
		if(result == 2){
			cout<<"Only one activite can be done, which can be"<<endl;
			cout<<"These activities are: "<<endl;
			for (int i = 0; i<v.size(); i++)
			{
				cout<<v[i].first<<" "<<v[i].second<<endl;
			}
		}
		else{
			cout<<"Total activities that can be done are "<<result<<endl;
			cout<<"These activities are: "<<endl;
			for (int i = 0; i<ans.size(); i++)
			{
				cout<<ans[i].first<<" "<<ans[i].second<<endl;
			}
		}
		cout<<endl<<endl;
	}

	
	return 0;
}
