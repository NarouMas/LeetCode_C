#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n1 = -1, n2 = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > n1)
                n2 = n1, n1 = nums[i];
            else if(nums[i] > n2)
                n2 = nums[i];
        }
        return (n1 - 1) * (n2 - 1);
    }
};