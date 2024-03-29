#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, m = -1;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            while(left < i && map[nums[i]] >= k)
                map[nums[left]]--, left++;
            map[nums[i]]++;
            if(i - left > m)
                m = i - left; 
        }
        return m + 1;
    }
};