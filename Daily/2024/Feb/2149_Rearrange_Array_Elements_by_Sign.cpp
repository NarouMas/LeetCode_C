#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int index_p = 0, index_n = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                res[index_p] = nums[i], index_p += 2;
            else
                res[index_n] = nums[i], index_n += 2;
        }
        return res;
    }
};