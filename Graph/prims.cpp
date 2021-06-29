/*
Prim's algo
select arbitary vertex s to start from a tree
all edges from s are inserted into set along with weight
get min weight edge and mark it visited and insert in set all edge from that node
check if already present in set with less weight
extract from top and check for unvisited edges
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int INF = 1e9;
int cost = 0;

int n; //no of node/vertex
int m; // no of edges
vector<vector<int>> g[N];
vector<int> dist(N), parent(N); //distance vect
vector<bool> vis(N);
void primsMST(int source)
{
    //initially dist of 0 is 0
    for (int i = 0; i < n; i++) //assigning dist of all nodes
    {
        dist[i] = INF;
    }
    set<vector<int>> s;    //weight, vertex
    dist[source] = 0;      //weight of 0 is 0
    s.insert({0, source}); //0,0
    while (!s.empty())
    {
        auto x = *(s.begin()); //getting top element
        s.erase(x);
        vis[x[1]] = true;      //1 as set is containing weight, vertex (1 is vertex)
        int u = x[1];          //edge
        int v = parent[x[1]];  //parent
        int w = x[0];          //weight
        cost += w;             // adding cost of MST
        for (auto i : g[x[1]]) //iterating through neighbours
        {
            if (vis[i[0]])
            {
                continue; //if visited then we know they are smallest so we continue
            }
            if (dist[i[0]] > i[1]) //i[1] is wight of edge
            {
                s.erase({dist[i[0]], i[0]});  //erasing old distance
                dist[i[0]] = i[1];            //updating new distance
                s.insert({dist[i[0]], i[0]}); //inserting new distance
                parent[i[0]] = x[1];          //updating parent
            }
        }
    }
}
int main()
{

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    cout << cost;
    return 0;
}