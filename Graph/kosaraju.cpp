/*
Strongly Connected Components (Kosaraju's Algo)
    
    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

reverse graph
order vector - dfs graph when reaches a visited node then backsrtrack and put in order vector
dfs in reverse graph each time increase counter

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> order;                                     //global order vector
    void rdfs(int s, vector<int> &vis1, vector<int> rev[]) //reverse dfs
    {
        vis1[s] = 1;
        for (auto i : rev[s])
        {
            if (!vis1[i])
            {
                rdfs(i, vis1, rev);
            }
        }
    }
    void dfs(int s, vector<int> &vis, vector<int> g[])
    {
        vis[s] = 1;
        for (auto i : g[s])
        {
            if (!vis[i])
            {
                dfs(i, vis, g);
            }
        }
        order.push_back(s); //when backstracking we are inserting to order vector
    }
    //Function to find the number of islands.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        order.clear();
        vector<int> rev[V];
        for (int y = 0; y < V; y++)
        {
            for (auto x : adj[y])
            {
                rev[x].push_back(y); //rev graph input
            }
        }
        vector<int> vis(V, 0); //visited vector
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj); //if not visited then dfs
            }
        }
        vector<int> vis1(V, 0); //for second dfs
        int count = 0;          //number of components
        for (int i = V - 1; i >= 0; i--)
        { //reverse loop of order vector
            if (!vis1[order[i]])
            {
                rdfs(order[i], vis1, rev);
                count++; //counter increases on each rdfs call
            }
        }
        return count;
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
                           // g[y].push_back(x); //5->1 (undirected)
    }
    Solution ob;
    int ans = ob.kosaraju(v, g);
    cout << ans << '\n';
    return 0;
}