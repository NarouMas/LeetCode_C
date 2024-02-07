#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(128, 0);
        for(char c: s)
            count[c]++;
        for(int i = 0; i < 128; i++)
            count[i] = count[i] * 1000 + i;
        sort(s.begin(), s.end(), bind(cmp, std::placeholders::_1, std::placeholders::_2, count));
        return s;
    }
    static bool cmp(char c1, char c2, vector<int> count)
    {
        if(count[c1] > count[c2])
            return true;
        return false;
    }
};