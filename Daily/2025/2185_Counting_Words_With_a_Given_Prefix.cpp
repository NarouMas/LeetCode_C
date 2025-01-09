#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto word: words)
        {
            if(word.size() < pref.size())
                continue;
            res++;
            for(int i = 0; i < pref.size(); i++)
                if(word[i] != pref[i])
                {
                    res--;
                    break;
                }
        }
        return res;
    }
};