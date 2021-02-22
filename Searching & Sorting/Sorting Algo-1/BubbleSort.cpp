#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int mycompare(int a,int b){
	return a>b;
}
void MakeCases(int *BestCase,int *WorstCase,int *AverageCase,int n){
	for (int i = 0; i < n; ++i)
	{
		//average case consist of random variables
		AverageCase[i]=rand();
	}
	for (int i = 0; i < n; ++i)
	{
		//average case consist of random variables
		BestCase[i]=AverageCase[i];
		WorstCase[i]=AverageCase[i];
	}
	//sorted in ascending order
	sort(BestCase,BestCase+n);
	//sorted in descending order
	sort(WorstCase,WorstCase+n,mycompare);
}

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void BubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}
int main(int argc, char const *argv[])
{
	
	int n=10000;
	int *BestCase=new int [n];
	int *WorstCase=new int [n];
	int *AverageCase=new int [n];
	
	MakeCases(BestCase,WorstCase,AverageCase,n);
	clock_t time_req; 
	time_req = clock();
	BubbleSort(BestCase,n);
	cout<<"Time Taken For Best case in Bubble sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	BubbleSort(WorstCase,n);
	cout<<"Time Taken For Worst case in Bubble sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	BubbleSort(AverageCase,n);
	cout<<"Time Taken For Average case in Bubble sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;;
	cout<<endl;
	return 0;
}