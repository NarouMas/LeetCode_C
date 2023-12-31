#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int m = 0, c1 = 0, c0 = 0;
        for(auto c:s)
            if(c == '1')
                c1++;
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == '1')
                c1--;
            else
                c0++;
            m = max(m, c0 + c1);
        }
        return m;
    }
};