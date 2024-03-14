#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> map;
        int psum = 0, res = 0;
        map[0] = 1;
        for(int n: nums)
        {
            psum += n;
            res += map[psum - goal];
            map[psum]++;
        }
        return res;
    }
};