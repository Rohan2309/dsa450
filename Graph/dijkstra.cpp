/*
Dijkstra's Algorithm

weighted graph (must be positive)
find single source shortest path from vertex u to all vertex 
if unreachable then -1


*/

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;

int main()
{          //weighted graph
    int v; //no of node/vertex
    int e; // no of edges

    cin >> v >> e;
    vector<int> dist(v + 1, inf);            //distance vector
    vector<vector<pair<int, int>>> g(v + 1); //for weighted graph
    for (int i = 0; i < e; i++)
    {                //taking e no. of edges input
        int x, y, w; //w is weight
        cin >> x >> y >> w;
        g[x].push_back({y, w}); //1->5
        g[y].push_back({x, w}); //5->1 (undirected)
    }

    int source; //source
    cin >> source;
    dist[source] = 0;      //initial distance of s is 0
    set<pair<int, int>> s; //set
    s.insert({0, source}); //inserting source (wt,vertex)
    while (!s.empty())
    {
        auto x = *(s.begin()); //smallest element of set
        s.erase(x);
        for (auto it : g[x.second]) //updating distance of neighbours
        {
            if (dist[it.first] > dist[x.second] + it.second) //it.first is node (v) and second is wt

            //dist[it.first] is ininity
            {
                s.erase({dist[it.first], it.first});         //erasing prev value
                dist[it.first] = dist[x.second] + it.second; //new value
                s.insert({dist[it.first], it.first});        //inserting new value
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] < inf)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << "-1"; //we couldn't reach the node
        }
    }
    return 0;
}
