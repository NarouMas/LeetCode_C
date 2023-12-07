#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map(256, -1);
        unordered_set<int> set;
        for(int i = 0; i < s.size(); i++)
        {
            if(map[s[i]] == -1)
            {
                if(set.find(t[i]) == set.end())
                {
                    map[s[i]] = t[i];
                    set.insert(t[i]);
                }
                else
                    return false;
            }
            else if(map[s[i]] != t[i])
                return false;
        }
        return true;
    }
};