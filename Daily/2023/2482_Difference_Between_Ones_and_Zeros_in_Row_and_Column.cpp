#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> r0(grid.size(), 0), r1(grid.size(), 0);
        vector<int> c0(grid[0].size(), 0), c1(grid[0].size(), 0);
        //vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    r1[i]++, c1[j]++;
                else
                    r0[i]++, c0[j]++;
            }
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                grid[i][j] = r1[i] + c1[j] - r0[i] - c0[j];
        return grid;
    }
};