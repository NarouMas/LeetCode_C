#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = 0, left, right;
        vector<int> res(nums.size());
        while(index < nums.size() && nums[index] < 0)
            index++;
        left = index -1, right = index;
        index = -1;
        while(true)
        {
            index++;
            if(left >= 0 && right < nums.size())
            {
                if(abs(nums[left]) < nums[right])
                    res[index] = nums[left] * nums[left], left--;
                else
                    res[index] = nums[right] * nums[right], right++;
            }
            else if(left >= 0)
                res[index] = nums[left] * nums[left], left--;
            else if(right < nums.size())
                res[index] = nums[right] * nums[right], right++;
            else
                break;
        }
        return res;
    }
};