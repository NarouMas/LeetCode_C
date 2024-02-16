#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<pair<int, int>> p;
        unordered_map<int, int> map;
        int res = 0;
        for(int n: arr)
            map[n]++;
        for(auto it: map)
            p.push_back({it.second, it.first});
        sort(p.begin(), p.end());
        for(int i = 0; i < p.size(); i++)
        {
            if(p[i].first <= k)
                k -= p[i].first;
            else
                res++;
        }
        return res;
    }
};