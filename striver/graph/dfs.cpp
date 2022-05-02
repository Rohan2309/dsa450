#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> v;

    void dfs(int pos, vector<int> &vis, vector<int> g[])
    {
        vis[pos] = 1; // making first node visited
        v.push_back(pos);
        for (auto x : g[pos]) // itr in it's adjacency values
        {
            if (!vis[x]) // if not visited
            {
                dfs(x, vis, g);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        v.clear();             // as global vector
        vector<int> vis(V, 0); // size V
        dfs(0, vis, adj);      // start from 0 pos
        return v;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
