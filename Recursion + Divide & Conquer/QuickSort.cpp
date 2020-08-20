#include <iostream>
using namespace std;

int partition(int *a,int s,int e){
	int i=s-1;
	int j=s;
	int pivot=a[e];
	for (; j < e; ++j)
	{
		/* code */
		if (a[j]<pivot)
		{
			/* code */
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}
void Quicksort(int *a,int s,int e){
	if(s>=e){
		return;
	}
	else{
		int pivot=partition(a,s,e);
		Quicksort(a,s,pivot-1);
		Quicksort(a,pivot+1,e);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int *a=new int [n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a[i];
	}
	Quicksort(a,0,n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout<<a[i]<<" ";
	}

	return 0;
}