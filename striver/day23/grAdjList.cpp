#include<bits/stdc++.h>
using namespace std;


int main(){
    //n is no of nodes
    //m is no of edges
    int n,m;
    cin>>n>>m;
    //for 1 base indexing
    vector<int> adj[n+1];
    //for all edges
    for(int i=0; i<m;++i){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return 0;
}