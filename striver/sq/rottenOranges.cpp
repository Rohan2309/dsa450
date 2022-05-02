/*
994. Rotting Oranges
Medium

6108

266

Add to List

Share
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())return 0;//base case
        int n = grid.size();//rows
        int m = grid[0].size();//cols
        int days=0;//answer
        int total=0;//total no of oranges
        int cnt=0;//count in queue, oranges rotten
        
        queue<pair<int,int>>q;//will store index i and j
        for(int i=0; i<n;++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]!=0) total++;//total number of oranges
                if(grid[i][j]==2)q.push({i,j});//pushing all rotten oranges
            }
        }
        //directions 
        //0,1 is right, 0,-1 is left, 1,0 is down and -1,0 is up
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty()){
            int sz = q.size();
            cnt+=sz;//total number of rotten oranges made by me
            while(sz--){
                //accessing data of q element
                int x = q.front().first;
                int y = q.front().second;
                q.pop();//removing that element from q
                
                //traversing 4 directions
                for(int i=0; i<4;++i){
                    int newX= x+dx[i];
                    int newY= y+dy[i];
                    //checking boundary conditions are met or if previously it's not a rotten orange or empty
                    if(newX<0 or newY<0 or newX>=n or newY>=m or grid[newX][newY]!=1){
                        continue;//we won't put it in queue
                    }
                    //if it is not
                    grid[newX][newY]=2;//mark it as rotten
                    q.push({newX,newY});//push it into queue
                }
                
            }
            if(!q.empty()) days++;//if q contains someting and we have rotten it, days will incre
        }
        //if total number of oranges rotten by me matches total count of oranges, we have answer which is days
        //if does not matches then fresh oranges are left and we return -1
        return total==cnt?days:-1;
    }
};
int main()
{

    return 0;
}