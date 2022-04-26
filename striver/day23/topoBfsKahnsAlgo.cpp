#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    // code here
	    queue<int>q;//for bfs (Kahn's algo)
	    vector<int>inDegree(N,0);//how many nodes incoming
	    for(int i=0; i<N; ++i){
	        for(auto it: adj[i]){//every neighbour will be an incoming node
	            inDegree[it]++;
	        }
	    }
	    //at first we insert 0 indegree to queue
	    for(int i=0; i<N; ++i){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>topo;
	    while(!q.empty()){
	        //take first node whose indegree is 0 and push it to vector
	        int x = q.front();
	        q.pop();
	        topo.push_back(x);
	        for(auto i: adj[x]){
	            //the ele which had inD=0 and was removed from q
	            //their neighbour's indegree will be deducted by 1
	            inDegree[i]--;
	            if(inDegree[i]==0)q.push(i);
	        }
	    }
	    return topo;
	}
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
