#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(256, 0), target(256, 0);
        int start = 0, end = -1, n = t.size(), rs = 0, re = 999999999;
        bool added;
        for(int i = 0; i < t.size(); i++)
        {
            target[t[i]]++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            added = false;
            if(n > 0)
            {
                if(count[s[i]] < target[s[i]])
                    n--;
                else if(n == t.size())
                    start++;
                if(target[s[i]])
                    count[s[i]]++, added = true;
                if(n == 0)
                    end = i;
            }
            if(n == 0)
            {
                if(target[s[i]] && !added)
                    count[s[i]]++;
                while(count[s[start]] > target[s[start]])
                {
                    int temp = start + 1;
                    end = i;
                    count[s[start]]--;
                    while(temp < s.size() && !count[s[temp]])
                        temp++;
                    if(temp < s.size() - 1)
                        start = temp;
                }
                if(end - start < re  - rs)
                    rs = start, re = end;
            }
        }
        if(end == -1)
            return "";
        //cout<<"start:"<<start<<" end:"<<end<<"\n";
        return s.substr(rs, re - rs + 1);
    }
};

int main()
{
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    string s2 = "a", t2 = "a";
    string s3 = "a", t3 = "aa";
    string s4 = "bba", t4 = "ab";
    Solution sol;

    cout<<sol.minWindow(s1, t1)<<"\n";
    cout<<sol.minWindow(s2, t2)<<"\n";
    cout<<sol.minWindow(s3, t3)<<"\n";
    cout<<sol.minWindow(s4, t4)<<"\n";
}