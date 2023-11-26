#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX, left = 0, right = 0;
        int sum = nums[0];
        while(left < nums.size())
        {
            if(sum < target)
            {
                right++;
                if(right >= nums.size())
                    break;
                sum += nums[right];
            }
            else if(sum >= target)
            {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
            if(left > right)
                left = right;
        }
        return (res == INT32_MAX) ? 0 : res;
    }
};

int main()
{
    vector<int> arr1 = {1,2,3,4,5};
    Solution sol;

    cout<<sol.minSubArrayLen(11, arr1)<<"\n";
}