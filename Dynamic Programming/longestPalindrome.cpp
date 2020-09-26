class Solution {
public:
    
string longest(string s , int l , int r){
    while(l >= 0 && r < s.size()){
        if(s[l] == s[r]){
            l-- ; 
            r++;
        }
        else 
            break;
    }
    
    string ans = s.substr(l+1 , r - l -1);
    return ans ;
}

string longestPalindrome(string s) {
    int n = s.size();
    int ans_len = 0 ;
    string ans;
    
    for(int i = 0 ;i < n; i++){
        string temp = longest(s , i , i);
        if(temp.size() > ans_len){
            ans_len = temp.size();
            ans = temp;
        }
        
        temp = longest(s , i , i+1);
        
         if(temp.size() > ans_len){
            ans_len = temp.size();
            ans = temp;
        }
    }
        return ans;
    }
};