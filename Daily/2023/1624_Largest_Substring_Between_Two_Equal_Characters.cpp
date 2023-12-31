#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(26, -1);
        int res = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(start[s[i] - 'a'] == -1)
                start[s[i] - 'a'] = i;
            else
                res = max(res, i - start[s[i] - 'a'] - 1);
        }
        return res;
    }
};