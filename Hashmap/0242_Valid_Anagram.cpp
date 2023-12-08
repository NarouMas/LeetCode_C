#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> map(26, 0);
        for(int i = 0; i < s.size(); i++)
            map[s[i] - 'a']++;
        for(int i = 0; i < s.size(); i++)
            if(map[t[i] - 'a']-- == 0)
                return false;
        return true;
    }
};