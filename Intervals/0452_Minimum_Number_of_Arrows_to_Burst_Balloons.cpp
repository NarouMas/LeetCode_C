#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> v;
        for(int i = 0; i < points.size(); i++)
            v.push_back({points[i][0], points[i][1]});
        sort(v.begin(), v.end(), cmp);
        int p = v[0].second, res = 1;
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i].first > p)
                p = v[i].second, res++;
        }
        return res;
    }
};