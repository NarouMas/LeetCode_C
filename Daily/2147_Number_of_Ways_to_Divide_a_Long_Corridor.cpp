#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> pos;
        for(int i = 0; i < corridor.size(); i++)
            if(corridor[i] == 'S')
                pos.push_back(i);
        if(pos.size() % 2 == 1 || pos.size() == 0)
            return 0;
        long long ans = 1;
        int prev = pos[1], mod = 1e9 + 7;
        for(int i = 2; i < pos.size(); i += 2)
        {
            int len = (pos[i] - prev);
            ans = (ans * len) % mod;
            prev = pos[i + 1];
        }
        return ans;
    }
};

int main()
{
    string s1 = "SSPPSPS";
    string s2 = "PPSPSP";
    string s3 = "S";
    string s4 = "PPSPSPPPSPPSPPSSPSSP";
    Solution sol;

    cout<<sol.numberOfWays(s1)<<"\n";
    cout<<sol.numberOfWays(s2)<<"\n";
    cout<<sol.numberOfWays(s3)<<"\n";
    cout<<sol.numberOfWays(s4)<<"\n";
}