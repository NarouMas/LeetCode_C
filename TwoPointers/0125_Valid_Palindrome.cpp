#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')))
            {
                i++;
                continue;
            }  
            if(!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')))
            {
                j--;
                continue;
            }   
            if(s[i] >= 'a')
                s[i] -= ' ';
            if(s[j] >= 'a')
                s[j] -= ' ';
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
};

int main()
{
    string s1 = "A man, a plan, a canal: Panama";
    Solution sol;

    cout<<sol.isPalindrome(s1)<<"\n";
}