#include <bits/stdc++.h>
using namespace std;

class Solution {
    //if have an odd length cycle not bipartite
public:
    bool dfs(int src,vector<vector<int>>& adj,vector<int> &color){
        if(color[src]==-1)color[src]=1;//if not colored then coloring
        for(auto x: adj[src]){//traversing for all neighbours
            if(color[x]==-1){
                color[x]=1-color[src];//if not colored, coloring with opp color
                if(!dfs(x,adj,color))return false;
            }//color already present and it it similar to adj node
            else if(color[x]==color[src])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){//node has not been visited
                if(!dfs(i,graph,color))return false;//graph can't be bipartite
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
