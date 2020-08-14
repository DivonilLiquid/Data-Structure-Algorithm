#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countsetbits(int n){
    int t=0;
    while(n){
        n= n & (n-1);// very fast approach
        t++;
    }
    return t;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int total=0;
        for(int i=a;i<=b;i++){
            total+=countsetbits(i);
        }
        cout<<total<<endl;
    }
    return 0;
}
