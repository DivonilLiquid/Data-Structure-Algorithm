/*
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.

*/
class Solution {
public:
    int fun(vector<string>& arr,int i,string a){
        //base case
        if(i==arr.size()){
            int m[26]={0};
            if(a.length()>26){
                return 0;
            }
            for(int k=0;k<a.length();k++){
                //if any a[k] char occurs twice, not possible
                if(m[a[k]-'a']==1){
                    return 0;
                }
                m[a[k]-'a']++;
            }
            return a.length();
        }
        int op1=0;
        int op2=0;
        //concatenate arr[i] with string a
        if(a.length()+arr[i].length()<=26){
            op1=fun(arr,i+1,a+arr[i]);
        }
        //don't combine that string with a
        op2=fun(arr,i+1,a);
        return max(op1,op2);
        
    }
    int maxLength(vector<string>& arr) {
        string ans="";
        if(arr.size()==0){
            return 0;
        }
        return fun(arr,0,ans);
    }
};
/*
Runtime: 72 ms, faster than 50.40% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
Memory Usage: 47.8 MB, less than 40.32% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.

*/