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

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void HeapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
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
	HeapSort(BestCase,n);
	cout<<"Time Taken For Best case in Heap sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	HeapSort(WorstCase,n);
	cout<<"Time Taken For Worst case in Heap sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	HeapSort(AverageCase,n);
	cout<<"Time Taken For Average case in Heap sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;;
	cout<<endl;
	return 0;
}