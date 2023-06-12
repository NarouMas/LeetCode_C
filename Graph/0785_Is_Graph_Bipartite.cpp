#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> qu;
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                qu.push(i);
                while(!qu.empty())
                {
                    int size = qu.size();
                    while (size--)
                    {
                        int from = qu.front();
                        qu.pop();
                        vector<int> node = graph[from];
                        for(int j = 0; j < node.size(); j++)
                        {
                            if(color[node[j]] == -1)
                            {
                                color[node[j]] = !color[from];
                                qu.push(node[j]);
                            }
                            else if(color[node[j]] == color[from])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    vector<vector<int>> graph2 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout<<sol.isBipartite(graph)<<"\n";  //1
    cout<<sol.isBipartite(graph2)<<"\n"; //0
    return 0;
}