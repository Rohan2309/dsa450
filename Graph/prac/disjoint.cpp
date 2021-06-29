/*
Disjoint Set Union

Set
S = {1,2,3,4} 
Leading element - Leader element for a set
Leader = 2
Parent[1]=Parent[2]=Parent[3]=Parent[4] = 2 
find a and b lies in same set
if leader is equal then yes

Naive,
Union(1,2) -> will make 1 as 2's parent
Union(3,4) -> will make 3 as 4's parent
but,
Union(2,4) -> will make 1 as 3's parent

Union by Size/Rank -> 0(aplha(n)) {where alpha is inv. ackerman func.} - 0(1)
if size of a < b
then b is parent
*/

/*
Cycle Detection in undirected graph using DSU


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
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    bool cycle = false;  // flag
    for (auto i : edges) //iterating through edges
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u); //finding parent
        int y = find_set(v);
        if (x == y) //same parents
        {
            cycle = true;
        }
        else
        {
            union_sets(u, v); //making same parent
        }
    }
    if (cycle)
    {
        cout << "Cycle is found";
    }
    else
    {
        cout << "Does not contain a cycle";
    }

    return 0;
}