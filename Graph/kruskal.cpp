/*
Kruskal's algo
Undirected and connected graph G(V,E)
Spanning tree - includes every Vertex of G. Every edge in the tree belongs to G
Cost - weight of the edges -> minimum (min spanning tree)
There can be many spanning trees
N vertex = N-1 edges (Spanning Tree)


Algo- *time ElogV  Space E+V*
sort edges in incre. order of their weights   (w,u,v)
iterate
if i'th edge makes cycle then skip i'th edge 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> size(N); //DSU using size

void make_set(int v) //initial
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) //finds parent
{
    if (v == parent[v]) //if already parent(leading element)
    {
        return v;
    }

    else                                        //path compression
    {                                           //reccursive
        return parent[v] = find_set(parent[v]); // all nodes will be pointing to main parent at top
    }
}

void union_sets(int a, int b)
{
    a = find_set(a); //finding parent
    b = find_set(b);
    if (a != b) // both belonging to diff. sets
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        //size of a is always bigger than b now
        parent[b] = a;      //making a as parent of b
        size[a] += size[b]; //adding size
    }
}
int main()
{
    //make set till N
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }
    int n; //no of node/vertex
    int m; // no of edges

    cin >> n >> m;
    vector<vector<int>> edges; //as we are only itr. through edges
    for (int i = 0; i < m; i++)
    { //taking e no. of edges input
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, x, y});
    }
    sort(edges.begin(), edges.end()); // sort acc to weight
    int cost = 0;

    for (auto i : edges) //iterating through edges
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u); //finding parent
        int y = find_set(v);
        if (x == y) //same parents
        {
            continue; //lies in same set , including this will make cycle
            //skipping
        }
        else
        {
            cout << u << " " << v << '\n'; //printing edges which are included
            cost += w;
            union_sets(u, v); //including in same set, making same parent
        }
    }
    cout << cost;

    return 0;
}