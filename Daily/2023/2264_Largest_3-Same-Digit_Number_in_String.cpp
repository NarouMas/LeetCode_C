#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int current = -1;
        for(int i = 2; i < num.size(); i++)
        {
            if(num[i] == num[i - 1] && num[i] == num[i - 2])
            {
                if(num[i] - '0' > current)
                    current = num[i] - '0';
            }
        }
        if(current == -1)
            return "";
        string res= "";
        res  += (char)(current + '0');
        return res + res[0] + res[0];
    }
};