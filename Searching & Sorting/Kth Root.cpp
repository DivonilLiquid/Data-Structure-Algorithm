#include <bits/stdc++.h>
using namespace std;
int main() {
   int t;
   cin>>t;
   long long int n,k;

   while(t--)
   {
        cin>>n>>k;
        long long int start=1,ans=0;
        // value of start variable should be 1 
        long long int end=n;
        while(start<=end)
        {
             long long int mid= (start+end)/2;
             // you were doing long long int mid= start+end/2; & not long long int mid= (start+end)/2; 
             if(pow(mid,k)<=n)
             {
                 ans=mid;
                 start=mid+1;
             }
             else
             {
                 end=mid-1;
             }
        }
        /*float inc=0.1;
        int p=3;
        for(int times=1;times<=3;times++)
        {
            while(pow(ans,k)<=n)
            {
                ans+=inc;
            }
            ans-=inc;
            inc/=10;
        }*/
        // perfroming increment operation on int variable which is not acceptable and also not asked in question
        cout<<ans<<endl;

   }
   return 0;

}
