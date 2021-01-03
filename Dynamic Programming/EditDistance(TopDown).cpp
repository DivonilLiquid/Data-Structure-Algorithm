/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.


TOP DOWN APPROACH WITH EXPLANATION
*/
class Solution {
public:
    int dp[505][505];
    int CalculateEditDistance(string &word1, string &word2, int e1,int e2){
        if(e1==0 && e2==0){
            return 0;
        }
        if(e1==0){
            return e2;
        }
        if(e2==0){
            return e1;
        }
        if(dp[e1][e2]!=-1){
            return dp[e1][e2];
        }
        if(word1[e1-1]==word2[e2-1]){
            return dp[e1][e2]=CalculateEditDistance(word1,word2,e1-1,e2-1);
        }
        //return min(Insert,min(delete,replace))
        //Insert = 1+CalculateEditDistance(word1,word2,e1,e2-1)
        //delete = 1+CalculateEditDistance(word1,word2,e1-1,e2)
        //replace = 1+CalculateEditDistance(word1,word2,e1-1,e2-1)

        //minimum of insert, delete and replace
                
        return dp[e1][e2]=min(1+CalculateEditDistance(word1,word2,e1,e2-1),min(1+CalculateEditDistance(word1,word2,e1-1,e2-1),1+CalculateEditDistance(word1,word2,e1-1,e2)));

    }
    int minDistance(string word1, string word2) {
        if(word1=="" && word2==""){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return CalculateEditDistance(word1,word2,word1.length(),word2.length());
    }
};
/*
Runtime: 60 ms, faster than 12.53% of C++ online submissions for Edit Distance.
Memory Usage: 7.7 MB, less than 63.59% of C++ online submissions for Edit Distance.
*/