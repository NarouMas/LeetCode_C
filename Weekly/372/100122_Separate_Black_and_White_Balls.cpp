#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int z = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
                continue;
            else if(i != z)
            {
                res += i - z;
                z++;
            }
            else
                z++;
        }
        return res;
    }
};

int main()
{
    string s1 = "101";
    string s2 = "100";
    string s3 = "0111";
    Solution sol;

    cout<<sol.minimumSteps(s1)<<"\n";  //1
    cout<<sol.minimumSteps(s2)<<"\n"; //2
    cout<<sol.minimumSteps(s3)<<"\n"; //0
}