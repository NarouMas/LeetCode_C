#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
            return res;
        string s = to_string(nums[0]);
        int prev = nums[0], first = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if((long long)nums[i] - (long long)nums[i - 1] > 1)
            {
                if(prev == first)
                    res.push_back(s);
                else
                {
                    s += "->" + to_string(prev);
                    res.push_back(s);
                }
                s = to_string(nums[i]);
                first = nums[i], prev = nums[i];
            }
            else
                prev = nums[i];
        }
        if(prev == first)
            res.push_back(s);
        else
        {
            s += "->" + to_string(prev);
            res.push_back(s);
        }
        return res;
    }
};