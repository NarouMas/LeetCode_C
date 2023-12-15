#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int m = intervals[0][1], l = intervals[0][0];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= m)
                m = max(m, intervals[i][1]);
            else
            {
                vector<int> v(2);
                v[0] = l, v[1] = m;
                res.push_back(v);
                l = intervals[i][0], m = intervals[i][1];
            }
        }
        vector<int> v(2);
        v[0] = l, v[1] = m;
        res.push_back(v);
        return res;
    }
};