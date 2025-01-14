#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26, 0);
        int res = 0;
        for(auto &c: s)
            count[c - 'a']++;
        for(auto &n: count)
        {
            if(n > 0)
            {
                if(n & 1)
                    res += 1;
                else
                    res += 2;
            }
        }
        return res;
    }
};