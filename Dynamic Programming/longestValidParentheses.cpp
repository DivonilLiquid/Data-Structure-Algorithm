class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>a;
        a.push(-1);
        int ans=0;
        int temp_ans=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                a.push(i);
            }
            else{
                a.pop();
                if(a.empty()==true){
                    a.push(i);
                }
                else{
                    temp_ans = i-(a.top());
                }
            }
            ans=max(ans,temp_ans);
        }
        return ans;
    }
};