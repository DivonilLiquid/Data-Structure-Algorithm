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
void InsertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
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
	InsertionSort(BestCase,n);
	cout<<"Time Taken For Best case in insertion sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	InsertionSort(WorstCase,n);
	cout<<"Time Taken For Worst case in insertion sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	InsertionSort(AverageCase,n);
	cout<<"Time Taken For Average case in insertion sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;;
	cout<<endl;
	return 0;
}