#include <iostream>
using namespace std;
void merge(int *a,int end,int start,int mid)
{
    int i=start,j=mid+1,k=start,c[50];
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            c[k]=a[i];
            k++;i++;
        }
        else{
            c[k]=a[j];
            k++;j++;
        }
    }
    while(i<=mid){
      c[k]=a[i];
      k++;i++;
    }
    while(j<=end){
        c[k]=a[j];
        k++;j++;
    }
    for(i=0;i<k;i++){
        a[i]=c[i];
    }
    return;
}
void mergesort(int *a,int n,int s){
    if(n==s)
    return ;
    else{
        int mid=(s+n)/2;
        mergesort(a,mid,s);
    
        mergesort(a,n,mid+1);
    // will merge two arrays
        merge(a,n,s,mid);
    
    }

}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    mergesort(a,n,0);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
