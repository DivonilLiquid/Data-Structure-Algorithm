#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
 
    /* create temp arrays */
    int L[n1], R[n2]; 
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
 
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
 
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
 
        merge(arr, l, m, r); 
    } 
}
int main() {
    int t=5;
    int n=10000;
    while(t--){
        cout<<"Implying for n equals to "<<n<<endl;
        int *a = new int [n];
        int *b = new int [n];
        int *c = new int [n];
        for (int i = 0; i < n; ++i)
        {
            a[i]=rand()%n;
            c[i]=(n-i);
            if(i<n/2){
                b[i]=rand()%(n/2);
            }
            else{
                b[i]=rand()%n+n/2;
            }
        }
        clock_t time_req;
        time_req = clock();
        mergeSort(a,0,n);
        cout<<"Time Taken required in average case of Merge sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
        time_req = clock() - time_req; 
        mergeSort(b,0,n);
        cout<<"Time Taken required in best case(ascending) of Merge sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
        time_req = clock() - time_req; 
        mergeSort(c,0,n);
        cout<<"Time Taken required in worst case(descending) of Merge sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
        cout<<endl<<endl;
        n+=n;
    }
    return 0;
}