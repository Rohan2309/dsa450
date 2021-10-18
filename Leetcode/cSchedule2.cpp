/*
210. Course Schedule II
Medium

4946

193

Add to List

Share
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    //cycle detection
    bool cycleDet(int u, vector<vector<int>>& adj, vector<int>&s, vector<int>&vis){
        vis[u]=1;//marking it visited
        for(int v: adj[u]){
            if(vis[v]==1){//if visited already
                return true;//we found a cycle
            }
            if(vis[v]==0 and cycleDet(v,adj,s, vis) ){
                return true;
            }
        }
        vis[u]=2;//we are done with it
        s.push_back(u);//stack will hold topological sort in rev order
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses); //adjacency list
        
        for(vector<int>& courses : prerequisites){
            adj[courses[1]].push_back(courses[0]);//2nd 1 connected tpo first 1
        }
        //adj list created
        vector<int>stk;//taking vectro instead of stack
        vector<int>vis(numCourses,0);//initially all unvisited
        for(int i=0; i< numCourses; ++i){
            if(vis[i]==0 and cycleDet(i,adj,stk, vis)){//unvisited and cycle detected
                return {};//return empty vector, no such ordering exists
            }
        }
        reverse(stk.begin(), stk.end());
        return stk;
    }
};

int main()
{
    
    return 0;
}