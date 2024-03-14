#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum1 = 0, sum2 = (1 + n) * n / 2;
        for(int i = 1; i <= n; i++)
        {
            sum1 += i;
            if(sum1 == sum2)
                return i;
            sum2 -= i;
        }
        return -1;
    }
};