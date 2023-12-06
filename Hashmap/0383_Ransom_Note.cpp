#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> c(26, 0);
        for(auto ch: magazine)
            c[ch - 'a']++;
        for(auto ch: ransomNote)
            if(!c[ch - 'a']--)
                return false;
        return true;
    }
};