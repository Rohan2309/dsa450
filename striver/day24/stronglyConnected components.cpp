#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
	//function for topo sort
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    //push node when all its children are visited
    st.push(node); 
}
//new dfs function for transpose graph
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; //print node
    vis[node] = 1; //mark it as visited
    for(auto it: transpose[node]) {//see neighbours
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n=6, m=7;
	vector<int> adj[n+1]; 
	adj[1].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(6);
	adj[5].push_back(4);
	adj[6].push_back(5);
	//directed graph created
	stack<int> st;//stack for topo sort using dfs
	vector<int> vis(n+1, 0); //visited array
	for(int i = 1;i<=n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	//topo sort implemented
	vector<int> transpose[n+1]; 
	
	for(int i = 1;i<=n;i++) {
	    vis[i] = 0; //remarking visited array as 0
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); //children->parent
	    }
	}
	//transpose is done
	
	//going on thr nodes according to fining time (topo sort)
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	
	return 0;
}