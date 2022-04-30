#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    int f(int i, int j, vector<vector<int>>& g, vector<vector<int>>& dp) {
        int res = 0;
        if(i < 0 or j < 0) return INT_MAX;//boundary cond base case
        if(i == 0 and j == 0) res = g[i][j];//base case reach dest   
        if(~dp[i][j]) return dp[i][j];       
        else if(i == 0) res = g[i][j] + f(i, j-1, g,dp);//only moving left
        else if(j == 0) res = g[i][j] + f(i-1, j, g,dp);//only moving up
        else res = g[i][j] + min(f(i-1, j, g,dp), f(i, j-1, g,dp)); //else prev val plus min of left and right
        return dp[i][j] = res;
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1, m-1, grid,dp);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
