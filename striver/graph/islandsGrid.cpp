#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j){
        if(i<0 or j<0 or i>=n or j>=m)return;
        if(grid[i][j]!='1')return;//we will skip 0 as we will consider only 1
        //there is 1
        grid[i][j]='2';//marking visited
        //sending dfs to all 4 sides
        dfs(grid,m,n, i+1, j);
        dfs(grid,m,n, i-1, j);
        dfs(grid,m,n, i, j+1);
        dfs(grid,m,n, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0)return 0;
        int m = grid[0].size();
        int c=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    dfs(grid,m,n, i, j);
                    c++;
                }
            }
        }
        return c;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
