#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for(auto s: strs)
        {
            string word = s;
            sort(word.begin(), word.end());
            map[word].push_back(s);
        }
        for(auto it: map)
            res.push_back(it.second);
        
        return res;
    }
};