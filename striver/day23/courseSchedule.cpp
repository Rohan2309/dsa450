
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& g) {
        bool flag = false;
        vector<vector<int>>adj(n); //adjacency list
        vector<int>inDegree(n);
        for(auto &it : g){
            adj[it[1]].push_back(it[0]);//2nd 1 connected to first 1
            inDegree[it[0]]++;
        }
        //adj list created and indegree array
        queue<int>q;//taking q for topological sort
        for(int i=0; i<n ;++i){//adding ele with 0 indegree in q
            if(!inDegree[i])q.push(i);
        }
        if(q.empty())return false;//no indegree 0
        vector<int>ans;
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);//pushing node with indegree 0 in ans
            q.pop();
            for(int it : adj[x]){//checking neighbours
                inDegree[it]--;//decreasing indegree of neighbours
                if(!inDegree[it])q.push(it);//if indegree becomes 0 push in q
            }
        }
        if(ans.size()==n)flag=true;//if topo can be performed return order
        return flag;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
