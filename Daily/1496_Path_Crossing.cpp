#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, pair_hash> set;
        int x = 0, y = 0;
        set.insert({0, 0});
        for(int i = 0; i < path.size(); i++)
        {
            switch (path[i])
            {
            case 'N':
                y += 1;
                break;
            case 'S':
                y -= 1;
                break;
            case 'W':
                x += 1;
                break;
            case 'E':
                x -= 1;
                break;
            default:
                break;
            }
            if(set.count({x, y}) != 0)
                return true;
            set.insert({x, y});
        }
        return false;
    }
    struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
};