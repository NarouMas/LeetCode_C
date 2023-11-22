#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ele
{
    int sum;
    int row;
    int val;
};

bool cmp(struct ele a, struct ele b)
{
    if(a.sum == b.sum)
        return a.row > b.row;
    else
        return a.sum < b.sum;
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<struct ele> arr;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                struct ele e;
                e.sum = i + j;
                e.row = i;
                e.val = nums[i][j];
                arr.push_back(e);
            }
        }
        vector<int> res(arr.size(), 0);
        sort(arr.begin(), arr.end(), cmp);

        for(int i = 0; i < arr.size(); i++)
            res[i] = arr[i].val;
        return res;
    }
};

int main()
{
    vector<vector<int>> arr1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> arr2 = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    //[[14,12,19,16,9],[13,14,15,8,11],[11,13,1]]
    //[14,13,12,11,14,19,13,15,16,1,8,9,11]
    vector<int> res;
    Solution sol;

    res = sol.findDiagonalOrder(arr1);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<"\n";

    res = sol.findDiagonalOrder(arr2);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<"\n";
}