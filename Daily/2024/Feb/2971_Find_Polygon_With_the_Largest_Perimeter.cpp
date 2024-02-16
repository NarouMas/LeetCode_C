#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <nums.size(); i++)
            sum += nums[i];
        for(int i = nums.size() - 1; i >= 2; i--)
        {
            sum -= nums[i];
            if(nums[i] < sum)
                return sum + (long long) nums[i];
        }
        return -1;
    }
};