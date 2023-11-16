#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<string> word = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> val =     {1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
        int i = 0, j = 0, res = 0;
        while(i < s.size())
        {
            if(j % 2 == 0)
            {
                if(s[i] == word[j][0])
                    res += val[j], i += 1;
                else
                    j++;
            }
            else if(i < s.size() - 1)
            {
                if(s[i] == word[j][0] && s[i + 1] == word[j][1])
                    res += val[j], i += 2;
                else
                    j++;
            }
            else
                j++;
        }
        return res;
    }
};

int main()
{
    string str1 = "DCXXI";
    Solution sol;

    cout<<sol.romanToInt(str1)<<"\n";
}