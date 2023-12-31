#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g = 0, p = 0, m = 0, res = 0;
        vector<int> count = {0, 0, 0};
        for(int i = 0; i < garbage.size(); i++)
        {
            countLetter(garbage[i], count);
            if(count[0] != 0)
                res += count[0] + g, g = 0;
            if(count[1] != 0)
                res += count[1] + p, p = 0;
            if(count[2] != 0)
                res += count[2] + m, m = 0;
            
            if(i != garbage.size() - 1)
                g += travel[i], p += travel[i], m += travel[i];
            count[0] = 0, count[1] = 0, count[2] = 0;
        }
        return res;
    }
private:
    void countLetter(string s, vector<int>& count)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'G')
                count[0]++;
            else if(s[i] == 'P')
                count[1]++;
            else if(s[i] == 'M')
                count[2]++;
        }
    }
};

int main()
{
    vector<string> g1 = {"G","P","GP","GG"};
    vector<int> t1 = {2,4,3};
    vector<string> g2 = {"MMM","PGM","GP"};
    vector<int> t2 = {3,10};
    Solution sol;

    cout<<sol.garbageCollection(g1, t1)<<"\n";
    cout<<sol.garbageCollection(g2, t2)<<"\n";
}