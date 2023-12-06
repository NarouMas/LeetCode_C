#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> r, c;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0)
                {
                    r.insert(i);
                    c.insert(j);
                }
        for(auto n:r)
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[n][i] = 0;
        for(auto n:c)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][n] = 0;
    }
};