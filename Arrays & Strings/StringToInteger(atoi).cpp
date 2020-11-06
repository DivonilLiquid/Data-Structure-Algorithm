/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 

Example 1:

Input: str = "42"
Output: 42
Example 2:

Input: str = "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: str = "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: str = "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: str = "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer. Thefore INT_MIN (−231) is returned.
 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits, ' ', '+', '-' and '.'.
*/
class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long long int ans=0;
        int flag=0;
        int i=1;
        if(s[0]=='-')flag=1;

            else if(s[0]<48||s[0]>57)
            {
                if(s[0]==' ')
                {
                   while(s[i]==' ')i++;
                    if(s[i]=='-') 
                    {
                        if(s[i+1]<48||s[i+1]>57) return 0;
                        flag=1; 
                        i++;
                    }
                     else if(s[i]=='+')
                    {
                        if(s[i+1]<48||s[i+1]>57) return 0;
                        ans=(int)(s[i+1]-'0');
                        i++;
                    }
                    else if(s[i]<48||s[i]>57) return 0;
                    ans=(int)(s[i]-'0');
                    i++; 
                }
                else if(s[0]=='+')
                {
                    if(s[1]<48||s[1]>57) return 0;
                    //cout<<ans<<endl;
                    ans=(int)(s[1]-'0');
                    //cout<<ans<<endl;
                    i++;
                }
                else return 0;
            }
            else ans=(int)(s[0]-'0');
            while(i<n)
            {
                if(s[i]>=48&&s[i]<=57)
                {
                    ans=ans*10+(int)(s[i]-'0');
                }
                else
                {
                    break;
                }
                if(ans>INT_MAX)
                {
                    if(flag)
                    {
                        ans=ans*-1;
                        if(ans<INT_MIN)return INT_MIN;
                    }
                    else
                        return INT_MAX;
                }
                i++;
            }
            if(flag)ans=ans*-1;
           return ans;
    }
};