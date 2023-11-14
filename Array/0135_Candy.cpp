#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        int sum = 0;
        for(int i = 1; i < ratings.size(); i++)
            if(ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
        for(int i = ratings.size() - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1])
                candy[i] = (candy[i] > candy[i + 1] + 1) ? candy[i] : candy[i + 1] + 1;
        for(int num : candy)
            sum += num;
        return sum;
    }
};