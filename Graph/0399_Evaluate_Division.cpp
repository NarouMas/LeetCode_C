#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int id1, id2;
        graph.resize(40, vector<double>(40, NAN));
        map.clear();
        ans.clear();
        for(int i = 0; i < equations.size(); i++)
        {
            id1 = getId(equations[i][0]), id2 = getId(equations[i][1]);
            graph[id1][id2] = values[i];
            graph[id2][id1] = 1.0 / values[i];
            graph[id1][id1] = 1, graph[id2][id2] = 1; 
        }
        for(int i = 0; i < queries.size(); i++)
        {
            id1 = getIdNotInsert(queries[i][0]), id2 = getIdNotInsert(queries[i][1]);
            if(id1 == -1 || id2 == -1)
            {
                ans.push_back(-1.0);
                continue;
            }
            if(!isnan(graph[id1][id2]))
            {
                ans.push_back(graph[id1][id2]);
                continue;
            }
            vector<bool> visited(40, false);
            visited[id1] = true;
            if(!dfs(id1, id1, id2, 1.0, visited))
                ans.push_back(-1.0);
        }
        return ans;
    }
private:
    unordered_map<string, int> map;
    vector<double> ans;
    vector<vector<double>> graph;
    int current_id = 0;
    //double NAN = 0.0/0.0;
    int getId(string s)
    {
        if(map.count(s) == 0)
            map.insert({s, current_id++});
        return map[s];
    }
    int getIdNotInsert(string s)
    {
        if(map.count(s) == 0)
            return -1;
        return map[s];
    }
    bool dfs(int start, int curr, int target, double value, vector<bool>& visited)
    {
        graph[start][curr] = value;
        if(curr == target)
        {
            ans.push_back(value);
            return true;
        }
        for(int i = 0; i < 40; i++)
            if(!isnan(graph[curr][i]) && !visited[i])
            {
                visited[i] = true;
                if(dfs(start, i, target, value * graph[curr][i], visited))
                    return true;
                visited[i] = false;
            }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> equations1 = {{"a", "b"}, {"b", "c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> ans1 = sol.calcEquation(equations1, values1, queries1);
    for(int i = 0; i < ans1.size(); i++)
        cout<<ans1[i]<<" "; //[6.00000,0.50000,-1.00000,1.00000,-1.00000]
    cout<<"\n";
    vector<vector<string>> equations2 = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    vector<double> ans2 = sol.calcEquation(equations2, values2, queries2);
    for(int i = 0; i < ans2.size(); i++)
        cout<<ans2[i]<<" "; //[3.75000,0.40000,5.00000,0.20000]
    cout<<"\n";
    vector<vector<string>> equations3 = {{"a", "b"}};
    vector<double> values3 = {0.5};
    vector<vector<string>> queries3 = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
    vector<double> ans3 = sol.calcEquation(equations3, values3, queries3);
    for(int i = 0; i < ans3.size(); i++)
        cout<<ans3[i]<<" "; //[0.50000,2.00000,-1.00000,-1.00000]
    cout<<"\n";
}