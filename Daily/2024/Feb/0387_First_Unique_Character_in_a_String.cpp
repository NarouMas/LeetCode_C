#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(128, 0);
        for(char c: s)
            map[c]++;
        for(int i = 0; i < s.size(); i++)
            if(map[s[i]] == 1)
                return i;
        return -1;
    }
};