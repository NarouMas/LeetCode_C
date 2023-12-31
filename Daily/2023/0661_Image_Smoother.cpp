#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> res(img.size(), vector<int>(img[0].size()));
        int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        for(int i = 0; i < img.size(); i++)
            for(int j = 0; j < img[0].size(); j++)
            {
                int sum = img[i][j], count = 1;
                for(int k = 0; k < 8; k++)
                    if(i + dy[k] >= 0 && i + dy[k] < img.size() && j + dx[k] >= 0 && j + dx[k] < img[0].size())
                        sum += img[i + dy[k]][j + dx[k]], count++;
                res[i][j] = sum / count;
            }
        return res;
    }
};