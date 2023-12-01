#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(auto c: t)
            map[c]++;
        int counter = t.size(), left = 0, right = 0, d = INT32_MAX, head = 0;
        while(right < s.size())
        {
            if(map[s[right++]]-- > 0)
                counter--;
            while (counter == 0)
            {
                if(right - left < d)
                    d = right - (head=left);
                if(map[s[left++]]++ == 0)
                    counter++;
            }
            
        }
        return d == INT32_MAX ? "" : s.substr(head, d);
    }
};