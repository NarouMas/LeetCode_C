#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> word = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> val =     {1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
        int i = 0;
        string res = "";
        while(num > 0)
        {
            if(num >= val[i])
                res += word[i], num -= val[i];
            else
                i++;
        }
        return res;
    }
};