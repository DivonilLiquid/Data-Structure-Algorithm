#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *a=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int i,j;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++){
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}