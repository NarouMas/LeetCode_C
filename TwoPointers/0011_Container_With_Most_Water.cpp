#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while(i < j)
        {
            if(height[i] < height[j])
                res = max(res, height[i] * (j - i)), i++;
            else
                res = max(res, height[j] * (j - i)), j--;
        }
        return res;
    }
};