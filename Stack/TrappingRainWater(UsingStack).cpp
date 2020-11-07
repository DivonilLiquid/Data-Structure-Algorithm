class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        //s.push(0);
        int res = 0;
        for(int i=0; i<height.size(); i++){
            while( (!s.empty()) && (height[i] > height[s.top()]) ){
                int TopHeightStack = height[s.top()];
                s.pop();
                if(s.empty()){
                    break;
                }
                int distance = i - s.top() -1;
                int MinHeight = min(height[s.top()],height[i]) - TopHeightStack;
                res += distance*MinHeight;
            }
            s.push(i);
        }
        return res;
    }
};
/*
Runtime: 16 ms Trapping Rain Water.
Memory Usage: 14.8 MB Trapping Rain Water.
*/