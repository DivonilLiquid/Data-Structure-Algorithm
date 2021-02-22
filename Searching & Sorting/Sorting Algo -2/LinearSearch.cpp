#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int LinearSearchPos(int *a,int start,int end,int key){
	for (int i = start; i <= end; ++i)
	{
		if(a[i]==key){
			return i+1;
		}
	}
	return -1;
}
		
int main(int argc, char const *argv[])
{
	int t=5;
	int n=1000000;
	while(t--){
		cout<<"Implying for n equals to "<<n<<endl;
		int *a = new int [n];
		for (int i = 0; i < n; ++i)
		{
			a[i]=rand()%n;
		}
		clock_t time_req;
		time_req = clock();
			
		int key = n+100;
		LinearSearchPos(a,0,n-1,key);
		cout<<"Time Taken For Worst case in Binary Search sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
		time_req = clock() - time_req; 
		key=a[0];
		LinearSearchPos(a,0,n-1,key);
		cout<<"Time Taken For Best case in Linear Search sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
		time_req = clock() - time_req; 
		key=rand()%n;
		LinearSearchPos(a,0,n-1,key);
		cout<<"Time Taken For Average case in Linear Search sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
		n+=n;
		cout<<endl<<endl;
	}
	return 0;
}