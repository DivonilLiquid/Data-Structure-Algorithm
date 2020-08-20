/*Take as input N, the size of array. Take N more inputs and store that in an array. Take N more inputs and store that in another array. Write a function which gives the intersection of two arrays in an ArrayList of integers and Print the ArrayList.

Input Format
First line contains N denoting the size of the two arrays. Second line contains N space separated integers denoting the elements of the first array. Third line contains N space separated integers denoting the elements of the second array.

Constraints
Length of Arrays should be between 1 to 100000.

Output Format
Display the repeating elements in a comma separated manner enclosed in square brackets. The numbers should be sorted in increasing order.

Sample Input
7
1 2 3 1 2 4 1
2 1 3 1 5 2 2
Sample Output
[1, 1, 2, 2, 3]*/


#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int *a=new int[n];
	int *b=new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>b[i];
	}
	map<int,int> m;
	//memset(m,0,sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		m[a[i]]++;
		m[b[i]]++;
	}
	for (auto i:m)
	{
		if(i.second>1){
			i.second/=2;
		}
	}
	vector<int> v;
	for (auto i:m)
	{
		if(i.second>1){
			int t=i.second;
			t/=2;
			for (int j = 0; j < t; ++j)
			{
				/* code */
				v.push_back(i.first);
			}
		}
	}
	int i=0;
	cout<<"[";
	int l=v.size();
	for (;i < l-1; ++i)
	{
		/* code */
		cout<<v[i]<<", ";
	}
	cout<<v[i]<<"]";
	return 0;
}