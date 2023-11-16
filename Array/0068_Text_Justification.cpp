#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> cur;
        int w_count = 0, s_count = 0;
        bool last = false, done =false;
        for(int i = 0; !done; i++)
        {
            bool enter = false;
            if(!last && (w_count == 0 || w_count + s_count + words[i].size() <= maxWidth))
            {
                cur.push_back(words[i]);
                w_count += words[i].size();
                s_count++, enter = true;;
                if(i == words.size() - 1)
                    last = true;
            }
            if(last || !enter)
            {
                int space = maxWidth - w_count, each, more;
                string entry = "";
                if(cur.size() == 1)
                    each = space, more = 0;
                else
                    each = space / (cur.size() - 1), more = space % (cur.size() - 1);
                for(int j = 0; j < cur.size(); j++)
                {
                    if(!last)
                    {
                        if(j != cur.size() - 1)
                        {
                            entry += cur[j] + string(each, ' ');
                            if(more > 0)
                                entry += " ", more--;
                        }
                        else
                           entry += cur[j]; 
                    }
                    else
                    {
                        if(j != cur.size() - 1)
                            entry += cur[j] + " ";
                        else
                            entry += cur[j];
                        
                    }
                }
                if(entry.size() != maxWidth)
                    entry += string(maxWidth - entry.size(), ' ');
                if(last)
                    done = true;
                res.push_back(entry);
                cur.clear();
                //w_count = 0, s_count = 0;
                if(!last)
                {
                    cur.push_back(words[i]);
                    w_count = words[i].size();
                    s_count = 1;
                    if(i == words.size() - 1)
                        last = true;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words2 = {"What","must","be","acknowledgment","shall","be"};
    vector<string> words3 = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> res;
    Solution sol;

    res = sol.fullJustify(words1, 16);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<"\n";
    cout<<"-----------------------------\n";
    res = sol.fullJustify(words2, 16);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<"\n";
    cout<<"-----------------------------\n";
    res = sol.fullJustify(words3, 20);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<"\n";
    cout<<"-----------------------------\n";

}