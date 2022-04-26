#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  bool solve(int pos, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[]) {
		vis[pos] = 1;
		dfsVis[pos] = 1;//came to currwnt path
		for (auto x : adj[pos]) {
			if (!vis[x]) {
				bool conf = solve(x, vis, dfsVis , adj);
				//going for dfs calls one after another we get a cycle
				if (conf == true) { //cycle present
					return true;
				}
			}
			else if (dfsVis[x]) { //when visited in main vis and vis in dfsVis then cycle
				return true;
			}
		}
		dfsVis[pos] = 0;//unmarking while going back
		return false;
	}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V, 0); //visited vector
		vector<int>dfsVis(V, 0); //internal dfs vis vector
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				bool c = solve(i, vis, dfsVis, adj); 
				if (c == true) {
					return true;
				}
			}
		}
		return false;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
