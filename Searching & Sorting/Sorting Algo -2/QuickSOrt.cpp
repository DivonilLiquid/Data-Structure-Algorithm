#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int partition(int *a,int n,int s){
    int i=s-1;
    int j=s;
    int pivot=a[n];
    for(j=s;j<n;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[n],a[i+1]);
    return i+1;
}
void quicksort(int *a,int n,int s){
    int p;
    if(s>=n)
    return;
    else
    {
      p=partition(a,n,s);
      quicksort(a,p-1,s);
      quicksort(a,n,p+1);
    }
    return;
}
int main() {
   int t=5;
    int n=100000;
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
            else if(i>(n-2) && i>(n/2)){
                b[i]=rand()%n+n/2;
            }
            else{
              b[i]=n/2;
            }
        }
        clock_t time_req;
        time_req = clock();
        quicksort(a,0,n);
        cout<<"Time Taken required in average case of Quick sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
        time_req = clock() - time_req; 
        quicksort(b,0,n);
        cout<<"Time Taken required in best case(modified) of Quick sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
        time_req = clock() - time_req; 
        quicksort(c,0,n);
        cout<<"Time Taken required in worst case(descending) of Quick sort is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
        cout<<endl<<endl;
        n+=n;
    }
    return 0;
}