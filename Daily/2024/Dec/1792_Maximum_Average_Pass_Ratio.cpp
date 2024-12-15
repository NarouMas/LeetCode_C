#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<array>
using namespace std;


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<
            pair<double, array<int, 2>>
        > pq;
        auto gain = [](double pass, double total){
            return (pass + 1) / (total + 1) - pass/total; 
        };
        double sum = 0;
        for(int i = 0; i < classes.size(); i++)
        {
            sum += double(classes[i][0]) / classes[i][1];
            pq.push({gain(classes[i][0], classes[i][1]), {classes[i][0], classes[i][1]}});
        }
            
        while(extraStudents--)
        {
            auto [currentGain, arr] = pq.top();
            sum += currentGain;
            pq.pop();
            pq.push({gain(arr[0] + 1, arr[1] + 1), {arr[0] + 1, arr[1] + 1}});
        }
        return sum / classes.size();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v1 = {{1,2}, {3,5}, {2,2}};
    cout<<sol.maxAverageRatio(v1, 2);
}