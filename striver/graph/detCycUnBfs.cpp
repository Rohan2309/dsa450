#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfs(int pos, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q; // current and prev
        vis[pos] = true;
        q.push({pos, -1}); // first node has no parent
        while (!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (prev != it)
                    return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false); // visited vector
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool f = bfs(i, adj, vis); 
                if (f)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
