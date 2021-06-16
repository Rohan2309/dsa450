/*
NODES - states or vetex. (users in fb)

EDGES - links b/w states in a graph. (connections b/w users)
-> undirected - two way (can go both ways a to b and b to a)
-> directed   - one way (can go either from a to b or b to a)

ADJACENT VERTICES -> they are two vertices with a direct edge connecting them
 
PATH ->  all vertices which come in the path of two given vertices is called their path

DEGREE OF VERTEX
-> INDEGREE - number of incoming edges to a node
-> OUTDEGREE - number of outgoing edges to a node

CONNECTED GRAPH -> each node has path from every other node
DISCONNECTED GRAPH -> does not have

CONNECTED COMPONENTS -> each connected graph in a disconnected graph

CYCLE -> path from a vertex to the same vertex (CYCLIC GRAPH)
NO CYCLE -> ACYCLIC GRAPH

REPRESENTATION -
-> adjacency matrix - 2D array where a[i][j] = 1 if there is an edge from i to j otherwise 0
   symmetric rep in undirected graph
-> adjacency list - Array of lists, where each a[i] is a list of nodes x, that are reachable from i


	ajd matrix (vXe) time
	adj matrix (v+e) time -> worst case is v^2 

SEARCHES -
-> DFS -> STACK
-> BFS -> QUEUE

WEIGHTED NODES -> values are associated with nodes
WEIGHTED EDGES -> values are associated with edges (Weighted graph)

TREE -> connected acyclic graph ( nimber of edges = total no of nodes - 1 )

DAG (directed acyclic graph)
COMPLETE GRAPH -> graph in which each vertex is connected to every other vertex (no of nodes = nC2 =  n*(n-1)/2)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    //graph
    int v; //no of node/vertex
    int e; // no of edges

    cin >> v >> e;

    //adj matrix

    int g[v + 1][v + 1]; //row col both defined
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            g[i][j] = 0; //initialize with 0
        }
    }
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    for (int i = 1; i <= v; i++)
    {
        cout << i << "--> "; //vertex number
        for (int j = 1; j <= v; j++)
        { //column
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    //adj list
    //making 2D graph
    //size allocating v no. of vertex
    //rows are defined v+1
    //columns are not defined

    // vector<int> g[v + 1];
    // for (int i = 0; i < e; i++) { //taking e no. of edges input
    // 	int x, y;
    // 	cin >> x >> y;
    // 	g[x].push_back(y); //1->5
    // 	g[y].push_back(x); //5->1
    // }

    //print

    // for (int i = 1; i <= v; i++) {
    // 	cout << i << "--> "; //vertex number
    // 	for (int j = 0; j < g[i].size(); j++) { //column
    // 		cout << g[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    return 0;
}