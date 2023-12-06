#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int res = 0, c = 1, d = 0;
        for(int i = 0; i < n; i++)
        {
            res += c, c++, d++;
            if(d % 7 == 0)
                c -= 6;
        }
        return res;
    }
};

int main()
{
    Solution sol;

    cout<<sol.totalMoney(20)<<"\n";
}