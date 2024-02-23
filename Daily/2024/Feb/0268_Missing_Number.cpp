#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, total = 0, n = nums.size();
        for(int num: nums)
            sum += num;
        total = n * (n + 1) / 2;
        return total - sum;
    }
};