/*
207. Course Schedule
Medium

7373

299

Add to List

Share
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool canFinish(int n, vector<vector<int>> &pre)
    {
        vector<vector<int>> adj(n, vector<int>()); //adjacency list initialized
        for (auto v : pre)
        {
            adj[v[1]].push_back(v[0]);
        }
        //adjacency list created
        vector<int> vis(n, 0); //visited array (0-> unvisited)
        for (int i = 0; i < n; ++i)
        {
            if (detCycle(adj, vis, i))
            { //there is a back edge then
                return false;
            }
        }
        return true; //otherwise return true
    }
    //back edge means, when a node is beigh visited (1, state) and is coming in the cycle
    bool detCycle(vector<vector<int>> &adj, vector<int> &vis, int pos)
    {
        if (vis[pos] == 1)
        {                //there is already a back edge
            return true; //yes, there is a backedge
        }
        if (vis[pos] == 0) //if not visited
        {                
            vis[pos] = 1; //being visited
            for (auto u : adj[pos])
            { //checking neighbours
                if (detCycle(adj, vis, u))
                { //if back edge
                    return true;
                }
            }
        }
        vis[pos] = 2; //completely visited
        return false; //if no back edge
    }
};

int main()
{

    return 0;
}