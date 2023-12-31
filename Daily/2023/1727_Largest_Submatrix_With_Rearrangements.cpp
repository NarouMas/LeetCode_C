#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0, n = matrix[0].size();
        vector<int> height(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                    height[j] = 0;
                else
                    height[j]++;
            }
            vector<int> temp = height;
            sort(temp.begin(), temp.end());

            for(int j = 0; j < temp.size(); j++)
                res = max(res, temp[j] * (n - j));
        }
        return res;
    }
};