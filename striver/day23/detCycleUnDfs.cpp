#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool dfs(int pos, int parent, vector<int> adj[], vector<bool> &vis) {
		vis[pos] = true;
		for (auto x : adj[pos]) {
			if (!vis[x]) {

				if (dfs(x, pos, adj, vis)) { //x is current node and pos is parent
					return true; //cycle present
				}
			}
			else if (x != parent) { //if visited but not parent
				return true;
			}
		}
		return false;
	}
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>vis(V, false); //visited vector
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				bool f = dfs(i, -1, adj, vis); //-1 is parent node at first
				if (f) {
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
