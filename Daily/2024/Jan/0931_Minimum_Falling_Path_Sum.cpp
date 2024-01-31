#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), res = INT32_MAX, n1, n2, n3;
        for(int n: matrix[0])
            res = min(res, n);
        for(int i = 1; i < n; i++)
        {
            res = INT32_MAX;
            for(int j = 0; j < n; j++)
            {
                n1 = n3 = INT32_MAX;
                if(j > 0)
                    n1 = matrix[i - 1][j - 1];
                n2 = matrix[i - 1][j];
                if(j < n - 1)
                    n3 = matrix[i - 1][j + 1];
                matrix[i][j] += min(n1, min(n2, n3));
                res = min(res, matrix[i][j]);
            }
        }
        return res;
    }
};