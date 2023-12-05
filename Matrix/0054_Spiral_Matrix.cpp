#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int dir = 0, s = matrix.size() * matrix[0].size(), x = 0, y = 0, nx, ny;
        vector<int> res;
        while(res.size() < s)
        {
            res.push_back(matrix[y][x]);
            matrix[y][x] = -300;
            nx = x + dx[dir], ny = y + dy[dir];
            if(nx >= matrix[0].size() || nx < 0 || ny >= matrix.size() || ny < 0 || matrix[ny][nx] == -300)
                dir = (dir + 1) % 4;
            
            x = x + dx[dir], y = y + dy[dir];
        }
        return res;
    }
};