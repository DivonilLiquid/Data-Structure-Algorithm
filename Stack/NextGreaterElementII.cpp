/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s; // index stack
        int n = nums.size();
        vector<int> res(n,-1);
        for (int i = 0; i < n * 2; i++) {
            int num = nums[i % n]; 
            while (!s.empty() && nums[s.top()] < num) {
                res[s.top()] = num;
                s.pop();
            }
            if (i < n) 
                s.push(i);
        }   
        return res;
    }
};
/*
Runtime: 52 ms, faster than 88.73% of C++ online submissions for Next Greater Element II.
Memory Usage: 24.4 MB, less than 5.49% of C++ online submissions for Next Greater Element II.
*/