/*
M-Coloring Problem 
Medium Accuracy: 47.46% Submissions: 26469 Points: 4
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool check(int node, int c[], bool graph[101][101], int n, int col){
    for(int i=0;i<n;++i){//checking all node
        if(i!=node and graph[i][node]==1 and c[i]==col)return false;
        //i!= node, not the node itself
        //graph[i][node]==1, adj node present, 1 means there is an edge
        //c[i]==col, the colour is equal to the color i'm trying to do
    }
    return true;
}


bool solve(int node,int m, int n, bool graph[101][101],int c[]){
    if(node==n)return true;//base, reaches end
    for(int i=1; i<=m;++i){//trying out all colors
        if(check(node,c,graph,n,i)){
            c[node]=i;//assigning color
            if(solve(node+1,m,n,graph,c))return true;//for next node
            c[node]=0;//backstracking
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V]={0};//color array of size v init with 0
    if(solve(0,m,V,graph,color))return true;//first node is 0
    return false;
}
int main()
{
    
    return 0;
}