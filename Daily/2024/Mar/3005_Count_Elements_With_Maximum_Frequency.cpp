#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int m = 0, res = 0;
        unordered_map<int, int> map;
        for(int n: nums)
        {
            map[n]++;
            if(map[n] > m)
                m = map[n]; 
        }
        for(auto it: map)
            if(it.second == m)
                res += m;
        return res;
    }
};