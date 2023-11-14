#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0;
        int maxLeft = 0, maxRight = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                maxLeft = max(maxLeft, height[left]);
                res += maxLeft - height[left];
                left++;
            }
            else
            {
                maxRight = max(maxRight, height[right]);
                res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};