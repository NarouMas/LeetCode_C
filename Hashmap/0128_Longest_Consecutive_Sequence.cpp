#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        map<int, int> m;
        int count = 1, res = 1;
        for(int n:nums)
            m[n]++;
        for(auto n:m)
        {
            if(m[n.first - 1] == 0)
                count = 1;
            else
                count++, res = max(res, count);
        }
        return res;
    }
};