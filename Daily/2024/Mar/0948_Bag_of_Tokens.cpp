#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int res = 0, score = 0, left = 0, right = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while(left <= right)
        {
            if(power >= tokens[left])
                power -= tokens[left], score++, left++, res = max(res, score);
            else if(score > 0)
                power += tokens[right], score--, right--;
            else
                break;
        }
        return res;
    }
};