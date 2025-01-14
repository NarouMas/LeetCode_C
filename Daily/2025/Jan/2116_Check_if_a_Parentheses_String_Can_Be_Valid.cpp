#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> openBrackets, opened;
        if(s.size() & 1)
            return false;
        for(int i = 0; i < s.size(); i++)
        {
            if(locked[i] == '0')
                opened.push(i);
            else if(s[i] == '(')
                openBrackets.push(i);
            else
            {
                if(!openBrackets.empty())
                    openBrackets.pop();
                else if(!opened.empty())
                    opened.pop();
                else
                    return false;
            }
        }
        while(!openBrackets.empty() && !opened.empty() && openBrackets.top() < opened.top())
        {
            openBrackets.pop();
            opened.pop();
        }
        return openBrackets.empty();
    }
};
