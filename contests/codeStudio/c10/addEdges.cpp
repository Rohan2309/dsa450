/*
Add Edges
Difficulty: MEDIUM
Contributed By
Vishal R S
|
Level 2
Avg. time to solve
15 min
Success Rate
85%
Problem Statement
A bipartite graph is a graph where each node is either coloured black or white and that for any edge, the endpoints of the edge are in different colours.
You are given an undirected tree of ‘N’ nodes. You can keep adding edges to it as long as the graph remains bipartite. What is the maximum number of edges you can add?
Note - If there already exists an edge between two nodes, you cannot add another. You also cannot add an edge from any node to itself. However, cycles are permitted.
For example:
If there is a tree of 4 nodes, with edges (1,2), (2,3) and (1,4), you can add an edge between nodes 3 and 4 and the graph still remains bipartite.
Input Format:
The first line contains 'T', denoting the number of test cases.
For each Test :
The first line contains a single integer ‘N’, representing the number of elements.
The next N-1 lines contain two integers ‘X’ and ‘Y’, indicating that there is an edge between node ‘X’ and ‘Y’.
Output Format:
For each test case, print one integer, the maximum number of edges you can add.
Note:
You are not required to print the expected output. It has already been taken care of. Just implement the function.
Constraints -
1 <= ‘T’ <= 10
2 <= ‘N’ <= 10^5
1 <= ‘X’,’Y’ <= N, X != Y
Note: It is guaranteed that the sum of N across all test cases will be at most 10^5.
Time Limit: 1 sec
Sample Input 1:
1
5
1 2
1 3
2 4
2 5
Sample Output 1
2
Explanation For Sample Input 1:
For test case 1:
    We can add two edges (3,4) and (3,5) and the graph still remains bipartite.
Sample Input 2:
1
3
1 2
1 3
Sample Output 2:
0


*/

#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int color, int p, vector<vector<int>>&adj){//will count no. of blacks
    int black= color;//initially 1 black
    //for particular node
    for(auto it: adj[node]){//traversing neigbours of node 1
        if(it!=p){//p is parent
            black+=dfs(it, !color,node,adj);//oppo colo and new parent is node itself
        }
    }
    return black;
}
long long maxEdges(int n, vector<pair<int,int>> edges)
{
    // Write your code here.
    //any graph having odd length cycle can't be bipartite
    
    //creating a graph
    vector<vector<int>>adj(n+1);
    for(auto it:edges){//traversing edges vector
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    //color the graph into b and w
    //assuming 1 to be black, 0 to be white
    //1st node is black and parent in -1 in func call
    int b = dfs(1,1,-1,adj);//no of blk nodes
    int w = n-b;//whites
    //b*w - (n-1)
    //3 b and 2 w so 3*2=6 {6-4}=2
    long long ans = 1LL * (b*w)-(n-1);
    return ans;
    
}
int main() {
	return 0;
}