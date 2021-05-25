#include <bits/stdc++.h>
using namespace std;
int func(vector<int>&nums,int n){
    vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,INT_MAX));
    for(int d=0;d<n;d++){
        for(int i=0;i<n-d;i++){
            if(d==0){
                dp[i][i]=0;
            }
            else if(d==1){
                dp[i][i+1]=nums[i]*nums[i+1];
            }
            else{
                //cout<<i<<","<<i+d<<endl;
                int sl=i;
                int er=i+d;
                for(int k=i;k<i+d;k++){                
                    int el = k;
                    int sr=k+1;
                    //cout<<nums[k]<<"->["<<i<<","<<k<<"] + ["<<k+1<<","<<i+d<<"]   ans: ";
                    int ans = dp[i][k]+dp[k+1][i+d];
                    int lsum=0;
                    for(int l=i;l<=k;l++){
                        lsum+=nums[l];
                    }
                    lsum%=100;
                    int rsum=0;
                    for(int r=k+1;r<=i+d;r++){
                        rsum+=nums[r];
                    }
                    rsum%=100;
                    int pro = (lsum*rsum);
                    ans+=pro;
                    //cout<<ans<<" pro: "<<pro<<endl;
                    dp[sl][er]=min(dp[sl][er],ans);
                }
            }
            
        }
        /*for(int p=0;p<n;p++){
            for(int q=0;q<n;q++){
                cout<<dp[p][q]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
    }
    return dp[0][nums.size()-1];
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        cout<<func(v,n)<<endl;
    }
    return 0;
}