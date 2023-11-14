#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank, index;
        for(int i = 0, j; i < gas.size(); i++)
        {
            tank = 0;
            index = i;
            j = 0;
            for(; j < gas.size() && tank >= 0; j++)
            {
                tank = tank + gas[index] - cost[index];
                index = (index + 1) % gas.size();
            }
            if(j == gas.size() && tank >= 0)
                    return i;
            i += j - 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    Solution sol;

    cout<<sol.canCompleteCircuit(gas1, cost1)<<"\n";
    cout<<sol.canCompleteCircuit(gas2, cost2)<<"\n";
}