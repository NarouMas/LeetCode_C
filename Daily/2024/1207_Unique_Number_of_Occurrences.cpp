#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        for(int n: arr)
            map[n]++;
        for(auto it: map)
        {
            if(set.count(it.second) != 0)
                return false;
            set.insert(it.second);
        }
        return true;
    }
};