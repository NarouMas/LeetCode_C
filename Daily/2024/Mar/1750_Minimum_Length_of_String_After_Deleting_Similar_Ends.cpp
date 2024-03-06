#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1, res;
        char c;
        while(left < right && s[left] == s[right])
        {
            c = s[left];
            while(left < right && s[left] == c)
                left++;
            while(right >= left && s[right] == c)
                right--;
        }
        cout<<"left:"<<left<<" right:"<<right<<"\n";
        res = right - left;
        return (res < 0)? 0: res + 1;
    }
};

int main()
{
    string s1 = "cabaabac";
    string s2 = "ca";
    string s3 = "aabccabba";
    string s4 = "aaaaaaaaaaaaaaaaaaaaa";
    string s5 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
    Solution sol;
    cout<<sol.minimumLength(s1)<<"\n";
    cout<<sol.minimumLength(s2)<<"\n";
    cout<<sol.minimumLength(s3)<<"\n";
    cout<<sol.minimumLength(s4)<<"\n";
    cout<<sol.minimumLength(s5)<<"\n";
}