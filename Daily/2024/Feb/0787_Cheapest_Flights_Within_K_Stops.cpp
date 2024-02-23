#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int wt;
    Edge(int s,int d,int w)
    {
        this->src = s;
        this->dest = d;
        this->wt = w;
    }
};
class Info
{
public:
    int vert;
    int stops;
    int cost;
    Info(int v,int cost,int stop)
    {
        this->vert =v;
        this->cost = cost;
        this->stops =stop;
    }
};

class Solution {
public:
    void createGraph(int n, vector<vector<int>>& flights, vector<vector<Edge>>& graph)
    {
        for (int i = 0; i < flights.size(); i++)
        {
            int src = flights[i][0];
            int dest = flights[i][1];
            int wt = flights[i][2];

            graph[src].push_back(Edge(src, dest, wt));
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        
        vector<vector<Edge>> graph(n);
        createGraph(n, flights, graph);

        vector<int>dist(graph.size(),INT_MAX);
        dist[src]=0;

        queue<Info>q;
        q.push(Info(src,0,0));

        while(!q.empty())
        {
            Info curr = q.front(); q.pop();

            if(curr.stops>k)
            {
                break;
            }

            for(int i=0;i<graph[curr.vert].size();i++)
            {
                Edge e  = graph[curr.vert][i];
                int u = e.src;
                int v = e.dest;
                int wt = e.wt;

                if ( dist[v] > curr.cost + wt) // Remove the curr.stops condition here
                {
                    dist[v] = curr.cost + wt;
                    q.push(Info(v, dist[v], curr.stops + 1));
                }
            }
        }
        return (dist[dst] == INT_MAX) ? -1: dist[dst];
    }
};