/*
Detect cycle in an undirected graph 

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int pos, int parent, vector<int> adj[], vector<bool> &vis)
    {
        vis[pos] = true;
        for (auto x : adj[pos])
        {
            if (!vis[x])
            {

                if (dfs(x, pos, adj, vis))
                {                //x is current node and pos is parent
                    return true; //cycle present
                }
            }
            else if (x != parent)
            { //if visited but not parent
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false); //visited vector
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool f = dfs(i, -1, adj, vis); //-1 is parent node at first
                if (f)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    int v; //no of node/vertex
    int e; // no of edges

    cin >> v >> e;

    vector<int> g[v];
    for (int i = 0; i < e; i++)
    { //taking e no. of edges input
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); //1->5
        g[y].push_back(x); //5->1 (undirected)
    }
    Solution ob;
    cout << ob.isCycle(v, g) << "\n";

    return 0;
}