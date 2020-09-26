class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
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
        return DP[sizeA][sizeB];
    }
};