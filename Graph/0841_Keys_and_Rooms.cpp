#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int count;
    vector<bool> visited;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        count = rooms.size();
        visited.resize(count, false);
        dfs(rooms, 0);
        return count == 0;
    }
    void dfs(vector<vector<int>>& rooms, int n)
    {
        count--;
        visited[n] = true;
        for(int i = 0; i < rooms[n].size(); i++)
        {
            if(!visited[rooms[n][i]])
                dfs(rooms, rooms[n][i]);
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> room1 = {{1}, {2}, {3}, {}};
    vector<vector<int>> room2 = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout<<sol.canVisitAllRooms(room1)<<"\n"; //1
    cout<<sol.canVisitAllRooms(room2)<<"\n"; //0
}