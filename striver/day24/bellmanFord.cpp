#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
//shortest path in a directed graph (work for negative weights) 
//can't work with -ve cycle
//-> can't find shortest path but can detect negative cycle
//undirected g -> directed graph
int main(){
    int N=6,m=7;
    vector<node> edges; 
	edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));
    //graph ceated with negative weights (all edges stored in struct node)
    int src=0;//source
    int inf = 10000000; 
    vector<int> dist(N, inf); 
    //distance arry created with first value 0 and rest infinity
    dist[src] = 0; //distance to source is 0
    for(int i = 1;i<=N-1;i++) { //relaxing n-1 times all edges
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {//formula for relaxation
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }
    //one more time relax it, if condition satifies
    //there is a negative cycle
    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    //if there is not a negative cycle, print shortest distance 
    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}