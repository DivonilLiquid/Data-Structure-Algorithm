#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findLHS(vector<int>& nums) {
        if(nums.size()==0 ||nums.size()==1){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int res = 0;
        while(i<nums.size()){
            int x=i;
            //cout<<"I is at(left pointer start) "<<i<<endl;
            while(nums[x]==nums[x+1] && ((x+1) < nums.size())){
                x++;
            }
            //cout<<"left pointer end is at "<<x<<endl;
            int y = x+1;
            //cout<<"Right pointer start is at "<<y<<endl;
            int next_pos = y;
            while(nums[y]==nums[y+1] && ((y+1) < nums.size())){
                y++;
            }
            //cout<<"Right pointer end is at "<<y<<endl;
            int diff = (y-i)+1;
            res = max(res,diff);
           // cout<<"Calculated difference is "<<diff<<" and maximum difference is "<<res<<endl;
            i=next_pos;
        }
        return res;
    }

int main(int argc, char const *argv[])
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(7);
    cout<<findLHS(nums)<<endl;
    return 0;
}
//[1,3,2,2,5,2,3,7]