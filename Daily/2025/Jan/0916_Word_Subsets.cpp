#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26, 0);
        vector<int> w(26, 0);
        vector<string> res;
        bool uni;
        for(int i = 0; i < words2.size(); i++)
        {
            fill(w.begin(), w.end(), 0);
            for(int j = 0; j < words2[i].size(); j++)
                w[words2[i][j] - 'a']++;
            for(int j = 0; j < 26; j++)
                if(w[j] > count[j])
                    count[j] = w[j];
        }
        for(int i = 0; i < words1.size(); i++)
        {
            uni = true;
            fill(w.begin(), w.end(), 0);
            for(int j = 0; j < words1[i].size(); j++)
                w[words1[i][j] - 'a']++;
            for(int j = 0; j < 26; j++)
            {
                if(w[j] < count[j])
                {
                    uni = false;
                    break;
                }   
            }
            if(uni)
                res.push_back(words1[i]);
        }
        return res;
    }
};

int main()
{
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e", "o"};
    Solution sol;
    vector<string> res = sol.wordSubsets(words1, words2);
    for(int i = 0; i < res.size(); i++)
        cout << res[i]<<"\n";
}