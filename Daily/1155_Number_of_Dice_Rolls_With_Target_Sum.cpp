#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int,int> & v) const {
            return v.first*31+v.second;
        }
    };
    unordered_map<pair<int, int>, int, pair_hash> m;
    int numRollsToTarget(int n, int k, int target) {
        m.clear();
        return dp(n, k, target);
    }
    
private:
    int dp(int d, int f, int target)
    {
        if(d == 0)
            return (target > 0)? 0: 1;
        if(m.find({d, target}) != m.end())
            return m[{d, target}];
        int res = 0;
        for(int i = max(0, target - f); i < target; i++)
            res = (res + dp(d - 1, f, i)) % (1000000000 + 7);
        m[{d, target}] = res;
        return res;
    }
};