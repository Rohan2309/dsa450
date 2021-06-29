/*
Graph Coloring

Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints. 

Vertex coloring is the most common graph coloring problem. The problem is, given m colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color. The other graph coloring problems like Edge Coloring (No vertex is incident to two edges of same color) and Face Coloring (Geographical Map Coloring) can be transformed into vertex coloring. 

Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. For example, the following can be colored minimum 2 colors. 
 
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int v; //no of node/vertex
    int e; // no of edges

    cin >> v >> e;

    vector<int> g[v + 1];
    for (int i = 0; i < e; i++)
    { //taking e no. of edges input
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); //1->5
        g[y].push_back(x); //5->1
    }

    int res[v];        //resultant array (Will get to know which color is in which node)
    bool available[v]; //available array (which color is available)

    res[0] = 0; //0'th node will be colored with 0

    for (int i = 1; i < v; i++) //initially -1 color
    {
        res[i] = -1;
    }
    for (int i = 0; i < v; i++) //initially all colors are available
    {
        available[i] = false;
    }
    int cn = 0; //chromatic number = 0;

    for (int i = 1; i < v; i++) //1 to v
    {
        for (auto x : g[i]) //checking adj elements
        {
            if (res[x] != -1) //already colored
            {
                available[res[x]] = true; //we can't use that color now
            }
        }
        int cr; //all colors
        for (cr = 0; cr < v; cr++)
        {
            if (available[cr] == false) //if that color is available
            {
                break;
            }
        }
        //we got the color to be used

        res[i] = cr;          //coloring node i with cr
        cn = max(cn, cr + 1); // as 0 based idxing

        for (auto x : g[i])
        {
            if (res[x] != -1)
            {
                available[res[x]] = false; //resetting value
            }
        }
    }
    cout << cn << endl;
    for (int i = 0; i < v; i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    solve();
    return 0;
}