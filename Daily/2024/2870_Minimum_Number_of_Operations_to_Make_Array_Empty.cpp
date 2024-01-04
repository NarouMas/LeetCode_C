#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 1, res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != nums.size() - 1 && nums[i] == nums[i + 1])
                count++;
            else if(count == 1)
                return -1;
            else
                res += (count + 2) / 3, count = 1;
        }
        return res;    
    }
};