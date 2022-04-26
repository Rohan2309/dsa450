#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
     vector<int> bfsOfGraph(int V, vector<int> g[]) {
        // Code here
        //no of nodes is v
        //adj is adj list of graph
        //first discover node -> 0
		//all adjacent node make it visited
		//travel line by line
		vector<int>v; //to store ans (bfs traversal)
		queue<int>q;
		q.push(0);
		vector<int> vis(V, 0); //visited vector, by default all values are 0
		vis[0] = 1;

		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			v.push_back(temp); //as already discovered

			for (auto x : g[temp]) //loop in adj elements
			{
				if (!vis[x]) //if not visited
				{
					vis[x] = 1;
					q.push(x);
				}

			}
		}
		return v;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
