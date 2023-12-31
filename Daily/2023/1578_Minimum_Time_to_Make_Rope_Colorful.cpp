#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<int> v;
        int res = 0;
        v.push_back(neededTime[0]);
        colors += '0';
        neededTime.push_back(0);
        for(int i = 1; i < colors.size(); i++)
        {
            if(colors[i] != colors[i - 1])
            {
                if(v.size() > 1)
                {
                    sort(v.begin(), v.end());
                    for(int j = 0; j < v.size() - 1; j++)
                        res += v[j];
                }
                v.clear();
            }
            v.push_back(neededTime[i]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string colors1 = "abaacddeeffffadcbffesssddzzzgggrsssaaadvvxx";
    vector<int> time1 = {5,6,8,4,2,3,8,4,2,3,4,4,5,3,1,3,9,8,4,2,4,8,7,8,5,3,2,1,6,3,1,6,3,1,2,9,1,3,2,8,4,1,3};
    string colors2 = "cddcdcae";
    vector<int> time2 = {4,8,8,4,4,5,4,2};

    cout<<sol.minCost(colors1, time1)<<"\n";
    cout<<sol.minCost(colors2, time2)<<"\n";
}