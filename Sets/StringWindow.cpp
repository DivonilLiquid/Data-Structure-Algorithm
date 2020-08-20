/*Ravi has been given two strings named string1 and string 2. He is supposed to find the minimum length substring of the string1 which contains all the characters of string2. Help him to find the substring

Input Format
The first line of the input contains string1. String1 can be a string containing spaces also. The second line of the input contains string2. String2 can be a string containing spaces also.

Constraints
Length of both the strings can be at max 10^4

Output Format
Output the substring in a single line. If no such substring exist then output "No String" without quotes

Sample Input
qwerty asdfgh qazxsw
qas
Sample Output
qazxs
Explanation
The substring "qazxs" is the shortest substring of s1 that contains all the characters of s2.
*/
#include "iostream"
#include "string"
#include "climits"
using namespace std;

string findSubstring(string str, string pat) {
    int len1 = str.length();
    int len2 = pat.length();
    int hash_str[256] = {0};
    int hash_pat[256] = {0};
    for(int i=0;i<len2;i++) {
        hash_pat[pat[i]]++;
    }
    int start = 0, start_index = -1, min_len = INT_MAX, count = 0;
    for(int i=0;i<len1;i++) {
        hash_str[str[i]]++;
        if(hash_pat[str[i]]!=0 and hash_str[str[i]]<=hash_pat[str[i]]){
            count++;
        }
        if(count == len2) {
            while(hash_str[str[start]]>hash_pat[str[start]] or hash_pat[str[start]]==0) {
                if(hash_str[str[start]]>hash_pat[str[start]]) {
                    hash_str[str[start]]--;
                }
                start++;
            }
            int len_window = i-start+1;
            if(len_window<min_len) {
                min_len=len_window;
                start_index = start;
            }
        }
    }
    if(start_index==-1) {
        return "No String";
    } else {
        return str.substr(start_index, min_len);
    }
}

int main(int argc, char* argv[])
{
    string str, pat;
    getline(cin, str);
    getline(cin, pat);
    cout<<findSubstring(str,pat);

    return 0;
}