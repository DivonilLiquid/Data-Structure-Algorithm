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

int ShellSort(int arr[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
    return 0; 
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
	ShellSort(BestCase,n);
	cout<<"Time Taken For Best case in Shell sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	ShellSort(WorstCase,n);
	cout<<"Time Taken For Worst case in Shell sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	ShellSort(AverageCase,n);
	cout<<"Time Taken For Average case in Shell sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;;
	cout<<endl;
	return 0;
}