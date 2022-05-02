#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //topo sort using bfs
        queue<int>q;
        vector<int>indegree(V,0);
        for(int i=0; i<V; ++i){
            for(auto it: adj[i])indegree[it]++;
        }
        //have indegree
        for(int i=0; i<V ;++i){
            if(indegree[i]==0)q.push(i);
        }
        //we only insert in queue when indegree is 0
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //when ele is popped indegree of adj is subtracted by 1
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(cnt==V)return false;//topo can be generated, does not have cycle
        else return true;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
