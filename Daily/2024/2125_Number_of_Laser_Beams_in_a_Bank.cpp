#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int currentCount, lastCount = 0, res = 0;
        for(int i = 0; i < bank.size(); i++)
        {
            currentCount = 0;
            for(int j = 0; j < bank[i].size(); j++)
            {
                if(bank[i][j] == '1')
                    currentCount++;
            }
            if(currentCount > 0)
                res += currentCount * lastCount,lastCount = currentCount;
        }
        return res;
    }
};