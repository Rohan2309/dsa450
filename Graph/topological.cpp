/*
Topological sort
Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> in(V, 0); //indegree vector
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                in[x]++; //calculating indegree
            }
        }

        for (int i = 0; i < V; i++)
        { //push 0 indegree elements in q
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        //bfs part
        while (!q.empty())
        {
            int td = q.front();
            q.pop();
            ans.push_back(td);
            for (auto x : adj[td])
            {
                in[x]--; //removing edge connection
                if (in[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        return ans;
    }
};

int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
            {
                return 0;
            }
        }
    }
}
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
                           //g[y].push_back(x); //5->1 (undirected)
    }
    Solution ob;
    vector<int> ans = ob.topoSort(v, g);
    cout << check(v, ans, g) << endl;
    return 0;
}