#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        unordered_map<string, int> count;
        vector<int> res;
        int left = 0, right = 0, total = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(count.find(words[i]) == count.end())
                count[words[i]] = 1;
            else
                count[words[i]]++;
        }
        for(int j = 0; j < words[0].size(); j++)
        {
            left = j, right = j, total = 0;
            map.clear();
            while(left < s.size() && right < s.size())
            {
                bool find = false;
                for(int i = 0; i < words.size(); i++)
                {
                    if(s.substr(right, words[0].size()).compare(words[i]) == 0)
                    {
                        find = true;
                        if(map.find(words[i]) != map.end())
                        {
                            if(map[words[i]] < count[words[i]])
                                map[words[i]]++, total++;
                            else
                            {
                                while(s.substr(left, words[0].size()).compare(words[i]) != 0)
                                {
                                    map[s.substr(left, words[0].size())]--, total--;
                                    if(map[s.substr(left, words[0].size())] == 0)
                                        map.erase(s.substr(left, words[0].size()));
                                    left += words[0].size();
                                }
                                left += words[0].size();
                            }  
                        }
                        else
                            map[words[i]] = 1, total++;

                        if(total == words.size())
                        {
                            res.push_back(left);
                            map[s.substr(left, words[0].size())]--;
                            total--;
                            if(map[s.substr(left, words[0].size())] == 0)
                                map.erase(s.substr(left, words[0].size()));
                            left += words[0].size();
                        }
                        right += words[0].size();
                        break;
                    }
                }
                if(!find)
                {
                    map.clear();
                    total = 0;
                    left = right + words[0].size();
                    right = left;
                }
            }
        }
        

        return res;
    }
};

int main()
{
    string s1 = "barfoothefoobarman"; vector<string> arr1 = {"foo","bar"};
    string s2 = "wordgoodgoodgoodbestword"; vector<string> arr2 = {"word","good","best","word"};
    string s3 = "barfoofoobarthefoobarman"; vector<string> arr3 = {"bar","foo","the"};
    string s4 = "wordgoodgoodgoodbestword"; vector<string> arr4 = {"word","good","best","good"};
    string s5 = "lingmindraboofooowingdingbarrwingmonkeypoundcake"; vector<string> arr5 = {"fooo","barr","wing","ding","wing"};
    string s6 = "aaaaaaaaaaaaaa"; vector<string> arr6 = {"aa","aa"};
    Solution sol;
    vector<int> res;
    
    res = sol.findSubstring(s1, arr1);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" "; //0 9
    cout<<"\n";

    res = sol.findSubstring(s2, arr2);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" "; //
    cout<<"\n";

    res = sol.findSubstring(s3, arr3);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" "; // 6 9 12
    cout<<"\n";

    res = sol.findSubstring(s4, arr4);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";  //8
    cout<<"\n";

    res = sol.findSubstring(s5, arr5);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" "; // 13
    cout<<"\n";

    res = sol.findSubstring(s6, arr6);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" "; // 0,1,2,3,4,5,6,7,8,9,10
    cout<<"\n";
}