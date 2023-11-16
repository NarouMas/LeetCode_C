#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, i;
        for(i = s.size() - 1; s[i] == ' '; i--);
        for(; i >=0 && s[i] != ' '; i--, res++);

        return res;
    }
};