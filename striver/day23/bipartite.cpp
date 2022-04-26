#include <bits/stdc++.h>
using namespace std;

class Solution {
     //if have an odd length cycle not bipartite
public:
    bool bfs(int src,vector<vector<int>>& graph,vector<int> &color){
        color[src]=1;//coloring source node with 1
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto i:graph[u]){
                if( color[i]==-1){//if not visited
                    color[i]=1-color[u];//Assign alternate color to its neighbors.
                    q.push(i);//pushing neigbours in q after they have color
                }
                else if(color[i]==color[u])return false; // If neighbor is of same color returnn false.
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){//node has not been visited
                if(!bfs(i,graph,color))return false;//graph can't be bipartgite
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
