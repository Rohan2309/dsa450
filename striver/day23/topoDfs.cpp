#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(int pos, vector<int>&vis, stack<int>&s, vector<int>adj[]){
	    vis[pos]=1;//marked as visited
	    for(auto i: adj[pos]){
	        if(!vis[i]){
	            dfs(i,vis,s,adj);
	        }
	    }
	    //when all neighbours are visited then only insert in stack
	    s.push(pos);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>s;//for topological sort
	    vector<int>vis(V,0);
	    for(int i=0; i<V; ++i){
	        if(!vis[i]){
	            dfs(i,vis,s,adj);
	        }
	    }
	    vector<int>topo;
	    while(!s.empty()){
	        int x = s.top();
	        topo.push_back(x);
	        s.pop();
	    }
	    return topo;
	}
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
