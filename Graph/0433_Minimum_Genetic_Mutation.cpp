#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> qu;
        int count = 0;
        qu.push(startGene);
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--)
            {
                startGene = qu.front();
                qu.pop();
                if(startGene == endGene)
                    return count;
                for(int i = 0; i < bank.size(); i++)
                    if(diff(startGene, bank[i]))
                    {
                        qu.push(bank[i]);
                        bank[i][0] = 'X';
                    }
            }
            count++;
        }
        return -1;
    }
private:
    bool diff(string& s1, string& s2)
    {
        int count = 0;
        if(s2[0] == 'X')
            return false;
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i])
                count++;
        return count == 1;
    }
};

int main()
{
    Solution sol;
    vector<string> bank1 = {"AACCGGTA"};
    vector<string> bank2 = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    cout<<sol.minMutation("AACCGGTT", "AACCGGTA", bank1)<<"\n"; //1
    cout<<sol.minMutation("AACCGGTT", "AAACGGTA", bank2)<<"\n"; //2
}