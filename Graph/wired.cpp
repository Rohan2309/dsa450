/*
Number of Operations to Make Network Connected

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

 

Example 1:



Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:



Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void dfs(int src, vector<int> g[], vector<int> &vis)
    {
        vis[src] = 1;
        for (auto x : g[src])
        {
            if (!vis[x])
            {
                dfs(x, g, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> g[n];
        int m = connections.size(); //no of edges
        if (m < n - 1)              //atleast n-1 edges should be there
        {
            return -1;
        }
        for (int i = 0; i < m; i++)
        {
            g[connections[i][0]].push_back(connections[i][1]); //making graph through adj list
            g[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n, 0); //visited vector
        int c = 0;             //components
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                c++;
                dfs(i, g, vis); //node, graph, visited
            }
        }
        return c - 1; //c-1 (components =c)
    }
};

int main()
{

    return 0;
}