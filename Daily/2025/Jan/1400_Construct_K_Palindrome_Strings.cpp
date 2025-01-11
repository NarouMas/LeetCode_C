#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> arr(26, 0);
        int low = 0, up = 0;
        for(auto c: s)
            arr[c-'a']++;
        for(auto n: arr)
        {
            if(n & 1)
                low += 1, n--;
            up += n;
        }
        return (k >= low && k <= low + up) ? true : false;
    }
};