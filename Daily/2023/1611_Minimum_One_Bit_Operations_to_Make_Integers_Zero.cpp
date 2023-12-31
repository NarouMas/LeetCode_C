#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1)
            return n;
        int bit = 0;
        while((1 << bit) <= n)
            bit++;
        return ((1 << bit) - 1) - minimumOneBitOperations(n - (1 << (bit - 1)));
    }
};

int main()
{
    Solution sol;

    //for(int i = 1, j = 1; i < 1025; i*=2, j++)
    //    cout<<i<<":"<<sol.minimumOneBitOperations(i)<<"\n";
    cout<<sol.minimumOneBitOperations(3)<<"\n";
    cout<<sol.minimumOneBitOperations(6)<<"\n";
    cout<<sol.minimumOneBitOperations(8)<<"\n";
    cout<<sol.minimumOneBitOperations(372544)<<"\n";
}