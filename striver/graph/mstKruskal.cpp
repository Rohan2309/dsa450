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

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    //path compression
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    //getting parents of both nodes
    u = findPar(u, parent);
    v = findPar(v, parent);
    //we attach the smaller rank node to the bigger rank
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    //if they are same , choose anyone and increase it's rank
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N=5,m=6;
	vector<node> edges; //u,v,w
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
    //sorting according to weights (ascending)
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);//parent of each node
    //make set operation
	for(int i = 0;i<N;i++) //every node is its own parent
	    parent[i] = i; 
	vector<int> rank(N, 0); //rank will be 0 at first
	
	int cost = 0;//cost for mst
	vector<pair<int,int>> mst; //will store answer
	for(auto it : edges) {//iterating over all edges
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
            //if doesn't belong to same component we can include in mst
	        cost += it.wt; //updating cost
	        mst.push_back({it.u, it.v}); //storing answer
	        unionn(it.u, it.v, parent, rank); //storing in same component
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}