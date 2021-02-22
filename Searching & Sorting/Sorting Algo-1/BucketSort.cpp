#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
float mycompare(float a,float b){
	return a>b;
}
void MakeCases(float *BestCase,float *WorstCase,float *AverageCase,float n){
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
void BucketSort(int *array, int size) {
   vector<float> bucket[size];
   for(int i = 0; i<size; i++) { //put elements into different buckets
      bucket[int(size*array[i])].push_back(array[i]);
   }

   for(int i = 0; i<size; i++) {
      sort(bucket[i].begin(), bucket[i].end()); //sort individual vectors
   }

   int index = 0;
   for(int i = 0; i<size; i++) {
      while(!bucket[i].empty()) {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}
int main(int argc, char const *argv[])
{
	
	int n=10000;
	float *BestCase=new float [n];
	float *WorstCase=new float [n];
	float *AverageCase=new float [n];
	
	MakeCases(BestCase,WorstCase,AverageCase,n);
	clock_t time_req; 
	time_req = clock();
	BucketSort(BestCase,n);
	cout<<"Time Taken For Best case in insertion sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	BucketSort(WorstCase,n);
	cout<<"Time Taken For Worst case in insertion sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	time_req = clock() - time_req; 
	BucketSort(AverageCase,n);
	cout<<"Time Taken For Average case in insertion sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;;
	cout<<endl;
	return 0;
}