#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26, 0);
        int res = 0;
        for(auto c: chars)
            charCount[c - 'a']++;
        for(auto s: words)
        {
            vector<int> count(26, 0);
            bool valid = true;
            for(auto c: s)
                count[c - 'a']++;
            for(int i = 0; i < 26; i++)
                if(count[i] > charCount[i])
                {
                    valid = false;
                    break;
                }
            if(valid)
                res += s.size();
        }
        return res;
    }
};