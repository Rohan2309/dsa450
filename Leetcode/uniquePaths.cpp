/*
62. Unique Paths
Medium

6349

259

Add to List

Share
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
*/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    int dp[m][n];
    int i, j;
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (i == 0 or j == 0)
            { //if we are in the first row or 1st col we simply put 1 as we can't go to more directions
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //adding top and left to get the number of ways
            }
        }
    }
    return dp[m - 1][n - 1]; //last cell will have all the posssible no of ways
}

int main()
{

    return 0;
}