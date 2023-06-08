#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size(), ans = 0;
        vector<int> height(c, 0), left(c, 0), right(c, c);
        for(int i = 0; i < r; i++)
        {
            int curLeft = 0, curRight = c;
            for(int j = 0; j < c; j++)
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft);
                else
                    left[j] = 0, curLeft = j + 1;
            }
            for(int j = c - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curRight);
                else
                    right[j] = c, curRight = j;
            }
            for(int j = 0; j < c; j++)
                ans = max(height[j] * (right[j] - left[j]), ans);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    cout<<sol.maximalRectangle(matrix)<<"\n"; // 6
}