/*
Rat in a Maze Problem - I 
Medium Accuracy: 37.73% Submissions: 100k+ Points: 4
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string s,
    vector < vector < int >> & vis) {
    if (i == n - 1 and j == n - 1) {//base case, when reaches end
      ans.emplace_back(s);
      return;
    }
//as lexicographic so , d then l, then r, then u
    // downward
    if (i + 1 < n and !vis[i + 1][j] and a[i + 1][j] == 1) {
      vis[i][j] = 1;//visited
      solve(i + 1, j, a, n, ans, s + 'D', vis);//next ele
      vis[i][j] = 0;//backstrack
    }

    // left
    if (j - 1 >= 0 and !vis[i][j - 1] and a[i][j - 1] == 1) {
      vis[i][j] = 1;
      solve(i, j - 1, a, n, ans, s + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n and !vis[i][j + 1] and a[i][j + 1] == 1) {
      vis[i][j] = 1;
      solve(i, j + 1, a, n, ans, s + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 and !vis[i - 1][j] and a[i - 1][j] == 1) {
      vis[i][j] = 1;
      solve(i - 1, j, a, n, ans, s + 'U', vis);
      vis[i][j] = 0;
    }

  }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis);
      return ans;
    }
};
int main()
{
    
    return 0;
}