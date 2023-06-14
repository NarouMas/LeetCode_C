#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define pii pair<int, int>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pii, vector<pii>, greater<pii> > qu;
        vector<vector<pii>> graph(n + 1);
        vector<int> distance(n + 1, INT_MAX);
        int ans = 0;
        for(int i = 0; i < times.size(); i++)
        {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        distance[k] = 0;
        qu.push({0, k});
        while(!qu.empty())
        {
            auto cur = qu.top();
            qu.pop();
            for(int i = 0; i < graph[cur.second].size(); i++)
            {
                int weight = graph[cur.second][i].second;
                int node = graph[cur.second][i].first;
                int update_weight = cur.first + weight;
                if(update_weight < distance[node])
                {
                    distance[node] = update_weight;
                    qu.push({update_weight, node});
                }
            }
        }
        for(int i = 1; i < distance.size(); i++)
        {
            if(distance[i] == INT_MAX)
                return -1;
            ans = max(ans, distance[i]);
        }
            
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    vector<vector<int>> times2 = {{1,2,1}};
    cout<<sol.networkDelayTime(times1, 4, 2)<<"\n"; //2
    cout<<sol.networkDelayTime(times2, 2, 2)<<"\n"; //-1
}