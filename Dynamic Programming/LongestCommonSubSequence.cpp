#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
#include<string>
using namespace std;
void LCS(string a, string b){
	int sizeA=a.length();
	int sizeB=b.length();
	int DP[sizeA+1][sizeB+1];
	memset(DP,0,sizeof(DP));
	for(int i=1;i<=sizeA;i++){
		for(int j=1;j<=sizeB;j++){
			if(a[i-1]==b[j-1]){
				DP[i][j]=1+DP[i-1][j-1];
			}
			else{
				DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
			}
		}
	}
  int i=sizeA,j=sizeB;
int index=DP[sizeA][sizeB];
char common[index+1];
common[index]='\0';
int temp = index;
  while(i>0 && j>0)
  {
	  if(a[i-1]==b[j-1])
	  {
		  common[index-1]=a[i-1];
		  i--;
		  j--;
      index--;
	  }
	  else if(DP[i-1][j]>DP[i][j-1])
	  {
		  i--;
	  }
	  else 
		  j--;

    }
    for(int k=0; k<temp; k++){
		  cout<<common[k];
	  }
      cout<<endl;
      
	return ;
}
int main() {
	string a,b;
	cin>>a>>b;
	cout<<"STRING IS: "<<endl;
	LCS(a,b);
  clock_t time_req; 
	time_req = clock();
	cout<<"Time Taken For Finding longest Common Subsequence is: "<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	
	return 0;
}