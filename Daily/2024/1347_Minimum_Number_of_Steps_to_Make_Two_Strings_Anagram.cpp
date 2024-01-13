#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26, 0);
        int c = 0;
        for(auto c: s)
            count[c - 'a']++;
        for(auto c: t)
            count[c - 'a']--;
        for(auto n: count)
            c += abs(n);
        return c >> 1;
    }
};