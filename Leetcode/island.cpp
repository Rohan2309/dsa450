/*
200. Number of Islands
Medium

10620

277

Add to List

Share
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<char>> &grid, int m, int n, int i, int j)
    {
        if (i < 0 or j < 0 or i >= n or j >= m)
        { //boundary conditions
            return;
        }
        if (grid[i][j] != '1')
        { //we will skip 0 as we will consider only 1
            return;
        }
        //there is 1
        grid[i][j] = '2'; //marking visited

        //sending dfs to all 4 sides
        dfs(grid, m, n, i + 1, j);
        dfs(grid, m, n, i - 1, j);
        dfs(grid, m, n, i, j + 1);
        dfs(grid, m, n, i, j - 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
        {
            return 0;
        }
        int m = grid[0].size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, m, n, i, j);
                    c++;
                }
            }
        }
        return c;
    }
};

int main()
{

    return 0;
}