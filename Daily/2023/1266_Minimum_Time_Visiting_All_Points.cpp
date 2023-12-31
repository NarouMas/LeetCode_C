#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 1; i < points.size(); i++)
        {
            int a = abs(points[i][0] - points[i - 1][0]);
            int b = abs(points[i][1] - points[i - 1][1]);
            res += max(a, b);
        }
        return res;
    }
};