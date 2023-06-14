#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        parent.clear();
        rank.clear();
        parent.resize(edges.size() + 1, -1);
        rank.resize(edges.size() + 1, 0);
        for(int i = 0; i < edges.size(); i++)
        {
            if(!union_foo(edges[i][0], edges[i][1]))
                return edges[i];
        }
        return edges[0];
    }
private:
    vector<int> parent;
    vector<int> rank;
    bool union_foo(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y)
            return false;
        else if(rank[root_x] < rank[root_y])
        {
            parent[root_x] = root_y;
            rank[root_y]++;
            return true;
        }
        else
        {
            parent[root_y] = root_x;
            rank[root_x]++;
            return true;
        }
    }
    int find(int x)
    {
        if(parent[x] == -1)
            return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges1 = {{1,2},{1,3},{2,3}};
    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<vector<int>> edges3 = {{3,4},{1,2},{2,4},{3,5}, {2,5}};
    vector<int> ans1 = sol.findRedundantConnection(edges1);
    vector<int> ans2 = sol.findRedundantConnection(edges2);
    vector<int> ans3 = sol.findRedundantConnection(edges3);
    cout<<ans1[0]<<" "<<ans1[1]<<"\n"; //2 3
    cout<<ans2[0]<<" "<<ans2[1]<<"\n"; //1 4
    cout<<ans3[0]<<" "<<ans3[1]<<"\n"; //2 5
}