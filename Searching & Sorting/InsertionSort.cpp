#include <iostream>
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
	int *a=new int [n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int i=1,j=0;
	//i->sorted
	//j->unsorted
	while(i<n){
		int key=a[i];
		j=i-1;
		while(j>=0 && key<a[j]){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	i++;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}