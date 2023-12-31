#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int res = 0, r2 = 1;
        string s2 = s;
        for(int i = 1; i < s.size(); i++)
            if(s[i] == s[i - 1])
                res++, s[i] = (s[i] == '0') ? '1': '0';
        s2[0] = (s2[0] == '0') ? '1': '0';
        for(int i = 1; i < s2.size(); i++)
            if(s2[i] == s2[i - 1])
                r2++, s2[i] = (s2[i] == '0') ? '1': '0';
        return min(res, r2);
    }
};