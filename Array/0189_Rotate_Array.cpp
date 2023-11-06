#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::rotate(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
    }
};

int main()
{
    vector<int> arr1 = {1,2,3,4,5,6,7};
    vector<int> arr2 = {-1,-100,3,99};
    Solution sol;

    sol.rotate(arr1, 3);
    sol.rotate(arr2, 2);

    for(int i = 0; i < arr1.size(); i++)
        cout<<arr1[i]<<" ";
    cout<<"\n";
    for(int i = 0; i < arr2.size(); i++)
        cout<<arr2[i]<<" ";
    cout<<"\n";
}