#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c0 = 0, c1 = 0;
        for(char c: s)
        {
            if(c == '0')
                c0++;
            else
                c1++;
        }
        return string(c1 - 1, '1') + string(c0, '0') + '1';
    }
};