#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        vector<vector<int>> res;
        vector<int> zero, one;
        for(int i = 0; i < matches.size(); i++)
        {
            if(m.count(matches[i][0]) == 0)
                m[matches[i][0]] = 0;
            m[matches[i][1]]++;
        }
        for(auto it: m)
        {
            if(it.second == 0)
                zero.push_back(it.first);
            else if(it.second == 1)
                one.push_back(it.first);
        }
        res.push_back(zero);
        res.push_back(one);

        return res;
    }
};