#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1E9 + 7;
        stack<int> st;
        int res = 0;

        for(int i = 0; i <= arr.size(); i++)
        {
            while (!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i]))
            {
                int mid = st.top();
                st.pop();
                int left = st   .empty() ? -1 : st.top();
                int right = i;
                long count = (mid - left) * (right - mid) % MOD;
                res += (count * arr[mid]) % MOD;
                res %= MOD;
            }
            st.push(i);
        }
        return int(res);
    }
};

int main()
{
    vector<int> arr1 = {3,1,2,4};
    Solution sol;

    cout<<sol.sumSubarrayMins(arr1)<<"\n";
}