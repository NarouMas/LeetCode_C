#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_set<string> set;
        graph.clear();
        map.clear();
        vertice.clear();
        for(int i = 0; i < tickets.size(); i++)
        {
            set.insert(tickets[i][0]);
            set.insert(tickets[i][1]);
        }
        for(auto s:set)
            vertice.push_back(s);
        sort(vertice.begin(), vertice.end());
        for(int i = 0; i < vertice.size(); i++)
            map.insert({vertice[i], i});
        graph.resize(vertice.size(), vector<int>(vertice.size(), 0));
        for(int i = 0; i < tickets.size(); i++)
        {
            graph[map[tickets[i][0]]][map[tickets[i][1]]] ++;
        }
        vector<string> res = vector<string>(1, "JFK");
        return dfs("JFK", tickets.size(), res);
    }
private:
    unordered_map<string, int> map;
    vector<vector<int>> graph;
    vector<string> vertice;
    vector<string> dfs(string cur, int depth, vector<string>& res)
    {
        int id = map[cur];
        if(depth == 0)
        {
            return res;
        }
        for(int i = 0; i < graph[id].size(); i++)
        {
            if(graph[id][i])
            {
                res.push_back(vertice[i]);
                graph[id][i]--;
                if(dfs(vertice[i], depth - 1, res).size() != 0)
                    return res;
                graph[id][i]++;
                res.pop_back();
            }
        }
        return vector<string>();
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> tickets1 = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    vector<vector<string>> tickets2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<vector<string>> tickets3 = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<vector<string>> tickets4 = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    vector<string> ans1 = sol.findItinerary(tickets1);
    vector<string> ans2 = sol.findItinerary(tickets2);
    vector<string> ans3 = sol.findItinerary(tickets3);
    vector<string> ans4 = sol.findItinerary(tickets4);
    for(int i = 0; i < ans1.size(); i++)
        cout<<ans1[i]<<" "; //["JFK","MUC","LHR","SFO","SJC"]
    cout<<"\n";
    for(int i = 0; i < ans2.size(); i++)
        cout<<ans2[i]<<" "; //["JFK","ATL","JFK","SFO","ATL","SFO"]
    cout<<"\n";
    for(int i = 0; i < ans3.size(); i++)
        cout<<ans3[i]<<" ";
    cout<<"\n";
    for(int i = 0; i < ans4.size(); i++)
        cout<<ans4[i]<<" "; // ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
    cout<<"\n";
}