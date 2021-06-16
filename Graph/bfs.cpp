/*
BFS of graph

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> g[])
    {
        // Code here
        //first discover node -> 0
        //all adjacent node make it visited
        //travel line by line
        vector<int> v; //to store ans (bfs traversal)
        queue<int> q;
        q.push(0);
        vector<int> vis(V, 0); //visited vector, by default all values are 0
        vis[0] = 1;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            v.push_back(temp); //as already discovered

            for (auto x : g[temp]) //loop in adj elements
            {
                if (!vis[x]) //if not visited
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
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
                           // g[y].push_back(x); //5->1
    }
    Solution ob;
    vector<int> ans = ob.bfsOfGraph(v, g);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}