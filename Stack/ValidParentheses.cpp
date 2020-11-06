/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
class Solution {
public:
    bool isValid(string s) {
        //'(', ')', '{', '}', '[' and ']'
        int n = s.length();
        stack <char> t;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[')
                t.push(ch);
            else{
                if(t.empty() == true){
                    return false;
                }
                char temp = t.top();
                if(s[i] == ')' && temp == '('){
                    t.pop();
                }
                else if(s[i] == '}' && temp == '{'){
                    t.pop();
                }
                else if(s[i] == ']' && temp == '['){
                    t.pop();
                }
                else{
                    t.push(s[i]);
                }
            }
        }
        if(t.empty()==true){
            return true;
        }
        else{
            return false;
        }
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.7 MB, less than 45.00% of C++ online submissions for Valid Parentheses.
*/