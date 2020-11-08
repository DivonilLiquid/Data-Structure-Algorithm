/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.
 

Constraints:

0 <= words.length <= 10^3
0 <= words[i].length <= 10^3
words[i] consists only of lowercase English letters.
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        
        int result = 0;
        
        for (int i=0; i<words.size(); ++i) 
        {
            for (auto c: words[i])
            {
                mask[i] |= 1 << (c - 'a');
            }
            
            for (int j=0; j<i; ++j)
            {
                if (!(mask[i] & mask[j]))
                {
                    result = max(result, int(words[i].size() * words[j].size()) );
                }
            }
        }
        
        return result;
    }
};
/*
Runtime: 48 ms, faster than 97.64% of C++ online submissions for Maximum Product of Word Lengths.
Memory Usage: 16.2 MB, less than 5.25% of C++ online submissions for Maximum Product of Word Lengths.
*/