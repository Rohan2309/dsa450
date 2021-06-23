/*
Rat in a Maze Problem - I 

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

class Solution
{
public:
    vector<string> ans; //global vec

    void dfs(int i, int j, string s, vector<vector<int>> &m, int n, vector<vector<int>> &vis)
    {
        if (i < 0 or j < 0 or i >= n or j >= n)
        { //boundary cond
            return;
        }
        if (m[i][j] == 0 or vis[i][j] == 1)
        { //block or else visited
            return;
        }
        if (i == n - 1 and j == n - 1)
        { //reached last pos
            ans.push_back(s);
            return;
        }
        vis[i][j] = 1; //visited

        //sending to all directions
        dfs(i - 1, j, s + 'U', m, n, vis);
        dfs(i + 1, j, s + 'D', m, n, vis);
        dfs(i, j - 1, s + 'L', m, n, vis);
        dfs(i, j + 1, s + 'R', m, n, vis);

        vis[i][j] = 0; //backstracking
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        ans.clear(); //clearing global vector
        int size = m.size();
        vector<vector<int>> vis(size, vector<int>(size)); //visited 2d vec n X n size
        if (m[0][0] == 0)
        { //first pos is 0 (we cannot start)
            return ans;
        }
        if (m[n - 1][n - 1] == 0)
        { //last pos is 0 (we can't reach destination)
            return ans;
        }
        string s = "";
        dfs(0, 0, s, m, n, vis); // 00 are initial points , s is string, m is 2d vec, n is size
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    Solution ob;
    vector<string> result = ob.findPath(m, n);
    if (result.size() == 0)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
    cout << endl;
    return 0;
}