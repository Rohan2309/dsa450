/*
DFS of Graph 

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //dfs print elements until leaf node or adj is visited

    vector<int> v;

    void solve(int pos, vector<int> &vis, vector<int> g[])
    {
        vis[pos] = 1; //making first node visited
        v.push_back(pos);
        for (auto x : g[pos]) //itr in it's adjacency values
        {
            if (!vis[x]) //if not visited
            {
                solve(x, vis, g);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        v.clear();             //as global vector
        vector<int> vis(V, 0); //size V
        solve(0, vis, adj);    //start from 0 pos
        return v;
    }
};

void FIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    FIO();
    int v; //no of node/vertex
    int e; // no of edges

    cin >> v >> e;

    vector<int> g[v];
    for (int i = 0; i < e; i++)
    { //taking e no. of edges input
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); //1->5
        g[y].push_back(x); //5->1
    }
    Solution ob;
    vector<int> ans = ob.dfsOfGraph(v, g);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}