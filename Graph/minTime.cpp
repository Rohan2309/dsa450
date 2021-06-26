/*
Minimum time taken by each job to be completed given by a Directed Acyclic Graph
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    //graph
    int v; //no of node/vertex
    int e; // no of edges

    cin >> v >> e;
    //adj list
    //making 2D graph
    //size allocating v no. of vertex
    //rows are defined v+1
    //columns are not defined

    vector<int> g[v + 1];
    vector<int> in(v + 1, 0); //indegree
    vector<int> ans;          //ans vec
    queue<int> q;             //queue for bfs
    for (int i = 0; i < e; i++)
    { //taking e no. of edges input
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); //1->5
        //g[y].push_back(x); //5->1
        in[y]++; //as x is connecting to y, so y's indegree increases
    }
    for (int i = 0; i < v; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
            ans[i] = 1; //ans is 1 as it's indegree is 0 at beginning
        }
    }

    while (!q.empty())
    {
        int td = q.front();
        q.pop();
        for (auto x : g[td])
        {            //seeing adj nodes
            in[x]--; //removing edges
            if (in[x] == 0)
            {
                ans[x] = ans[td] + 1; //time is (time of parent node + 1)
                q.push(x);
            }
        }
    }

    //printing answer
    for (int i = 1; i <= v; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}