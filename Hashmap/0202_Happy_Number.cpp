#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int num;
        while(n != 1)
        {
            if(set.find(n) != set.end())
                return false;
            set.insert(n);
            num = 0;
            while (n > 0)
                num += (n % 10) * (n % 10), n /= 10;
            n = num;
        }
        return true;
    }
};