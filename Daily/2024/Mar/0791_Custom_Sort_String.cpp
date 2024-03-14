#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> o;

class Solution {
public:
    string customSortString(string order, string s) {
        o = vector(128, 999);
        for(int i = 0; i < order.size(); i++)
            o[order[i]] = i;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
    static bool cmp(char c1, char c2)
    {
        return o[c1] < o[c2];
    }
};