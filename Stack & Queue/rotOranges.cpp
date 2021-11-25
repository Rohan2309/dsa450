/*
Rotten Oranges 
Medium Accuracy: 50.57% Submissions: 20206 Points: 4
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    { //storing rotten apples inside queue
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    int count = 0;    //ans
    q.push({-1, -1}); //delimeter
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        if (q.size() == 1 and (i == -1 and j == -1))
        { //condition when there is no set of second elements
            q.pop();
            break;
        }
        else if (q.size() > 1 and (i == -1 and j == -1))
        {            //condition when there is set of second eles
            count++; //increasing counter
            q.pop();
            q.push({-1, -1}); //agaimn delimeter
        }
        else
        {
            if ((i - 1) >= 0 and grid[i - 1][j] == 1)
            { //if element is lying in grid and is 1
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }
            if ((i + 1) < n and grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }
            if ((j + 1) < m and grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }
            if ((j - 1) >= 0 and grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }
            q.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            { //if any unrotten left
                return -1;
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}