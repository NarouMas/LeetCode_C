#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, nrob = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int new_rob = nrob + nums[i];
            int new_nrob = max(rob, nrob);
            rob = new_rob;
            nrob = new_nrob;
        }
        return max(rob, nrob);
    }
};