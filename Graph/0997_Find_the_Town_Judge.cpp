#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        vector<int> in(n + 1, 0);
        vector<bool> out(n + 1, false);
        for(int i = 0; i < trust.size(); i++)
        {
            in[trust[i][1]]++;
            out[trust[i][0]] = true;
        }
        for(int i = 1; i < n + 1; i++)
            if(!out[i] && in[i] == n - 1)
                return i;
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> trust = {{1,3},{2,3}};
    vector<vector<int>> trust2 = {{1,3},{2,3},{3,1}};
    vector<vector<int>> trust3 = {{1,2}};
    cout<<sol.findJudge(3, trust)<<"\n";  //3
    cout<<sol.findJudge(3, trust2)<<"\n"; //-1
    cout<<sol.findJudge(2, trust3)<<"\n"; //2
    return 0;
}