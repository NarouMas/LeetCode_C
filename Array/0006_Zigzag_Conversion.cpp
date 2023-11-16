#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int step = (numRows - 1) * 2;
        string res = "";
        for(int i = 0; i <numRows; i++)
        {
            for(int j = i; j < s.size(); j += step)
            {
                res += s[j];
                if(i != 0 && i != numRows - 1)
                {
                    int mid = j + (step - i * 2);
                    if(mid < s.size())
                        res += s[mid];
                }
            }
        }
        return res;
    }
};