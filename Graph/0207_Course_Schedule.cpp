#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> qu;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        int num;
        for(int i = 0; i < prerequisites.size(); i++)
        {
           int pre = prerequisites[i][1];
           int post = prerequisites[i][0];
           graph[pre].push_back(post);
           indegree[post]++;
        }
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                qu.push(i);
        while(!qu.empty())
        {
            num = qu.front();
            numCourses--;
            qu.pop();
            for(int i = 0; i < graph[num].size(); i++)
            {
                if(--indegree[graph[num][i]] == 0)
                    qu.push(graph[num][i]);
            }
        }
        return numCourses == 0;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> course1 = {{1, 0}};
    vector<vector<int>> course2 = {{1, 0}, {0 ,1}};
    vector<vector<int>> course3 = {{2, 1}, {1 ,0}};
    vector<vector<int>> course4 = {{2, 1}, {1 ,0}, {0, 2}};
    vector<vector<int>> course5 = {{1, 0}, {1 ,2}, {0, 1}};
    cout<<sol.canFinish(2, course1)<<"\n"; //1
    cout<<sol.canFinish(2, course2)<<"\n"; //0
    cout<<sol.canFinish(3, course3)<<"\n"; //1
    cout<<sol.canFinish(3, course4)<<"\n"; //0
    cout<<sol.canFinish(3, course5)<<"\n"; //0
}