/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10

*/
class Solution {
  
public:
    int largestRectangleArea(vector<int>& heights) {
         heights.push_back(0);//to deal with last element in heights
        const int n = heights.size();
        //initialise stack of int variable
        stack<int> s;
        int area = 0;
        int res =0;
        int i=0;
        while(i<n){ 
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i++);
            }
            else{
                int Element = heights[s.top()];
                s.pop();
                if(s.empty()==true){
                    area = Element * i;
                }
                else{
                    area = Element * ( i - s.top() -1);
                }
            }
            res = max(res, area);
        }
        return res;
    }
};
/*
Success
Details 
Runtime: 24 ms, faster than 69.32% of C++ online submissions for Largest Rectangle in Histogram.
Memory Usage: 14.5 MB, less than 9.77% of C++ online submissions for Largest Rectangle in Histogram.
*/