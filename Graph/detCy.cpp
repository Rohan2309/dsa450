/*
Detect cycle in a directed graph 

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int pos, vector<int> &vis, vector<int> &ord, vector<int> adj[])
    {
        vis[pos] = 1;
        ord[pos] = 1;
        for (auto x : adj[pos])
        {
            if (!vis[x])
            {
                bool conf = solve(x, vis, ord, adj);
                if (conf == true)
                { //cycle present
                    return true;
                }
            }
            else if (ord[x])
            { //if visited but order is 1
                return true;
            }
        }
        ord[pos] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {

        // code here
        vector<int> vis(V, 0); //visited vector
        vector<int> ord(V, 0); //order vector
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool c = solve(i, vis, ord, adj);
                if (c == true)
                {
                    return true;
                }
            }
        }
        return false;
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
    //graph
    int v; //no of node/vertex
    int e; // no of edges

    cin >> v >> e;

    vector<int> g[v];
    for (int i = 0; i < e; i++)
    { //taking e no. of edges input
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); //1->5
                           // g[y].push_back(x); //5->1
    }
    Solution ob;
    cout << ob.isCyclic(v, g) << "\n";

    return 0;
}