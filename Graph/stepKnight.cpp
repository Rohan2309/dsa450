/*
Steps by Knight 

Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        // Code here
        int x1 = KnightPos[0];
        int y1 = KnightPos[1];
        int x2 = TargetPos[0];
        int y2 = TargetPos[1];
        int a[n + 1][n + 1];
        if (x1 == x2 and y1 == y2)
        { //start and end idx at same point
            return 0;
        }
        for (int i = 0; i < n; i++)
        { //arr all values set to 0
            for (int j = 0; j < n; j++)
            {
                a[i][j] = 0;
            }
        }
        queue<pair<int, int>> q;           //for bfs
        q.push(make_pair(x1 - 1, y1 - 1)); // pushing 0 based indexing
        while (!q.empty())
        {
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();
            //going to 8 directions
            if ((i + 1) >= 0 and (i + 1) < n and (j + 2) >= 0 and (j + 2) < n and a[i + 1][j + 2] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i + 1][j + 2] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i + 1, j + 2)); //pushing point in q
            }
            if ((i - 1) >= 0 and (i - 1) < n and (j + 2) >= 0 and (j + 2) < n and a[i - 1][j + 2] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i - 1][j + 2] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i - 1, j + 2)); //pushing point in q
            }
            if ((i - 2) >= 0 and (i - 2) < n and (j + 1) >= 0 and (j + 1) < n and a[i - 2][j + 1] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i - 2][j + 1] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i - 2, j + 1)); //pushing point in q
            }
            if ((i + 2) >= 0 and (i + 2) < n and (j + 1) >= 0 and (j + 1) < n and a[i + 2][j + 1] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i + 2][j + 1] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i + 2, j + 1)); //pushing point in q
            }
            if ((i - 1) >= 0 and (i - 1) < n and (j - 2) >= 0 and (j - 2) < n and a[i - 1][j - 2] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i - 1][j - 2] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i - 1, j - 2)); //pushing point in q
            }
            if ((i + 1) >= 0 and (i + 1) < n and (j - 2) >= 0 and (j - 2) < n and a[i + 1][j - 2] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i + 1][j - 2] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i + 1, j - 2)); //pushing point in q
            }
            if ((i - 2) >= 0 and (i - 2) < n and (j - 1) >= 0 and (j - 1) < n and a[i - 2][j - 1] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i - 2][j - 1] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i - 2, j - 1)); //pushing point in q
            }
            if ((i + 2) >= 0 and (i + 2) < n and (j - 1) >= 0 and (j - 1) < n and a[i + 2][j - 1] == 0)
            //checking boundary cond and if point is 0 we can go
            {
                a[i + 2][j - 1] = a[i][j] + 1;   //increasing step count
                q.push(make_pair(i + 2, j - 1)); //pushing point in q
            }
        }
        return a[x2 - 1][y2 - 1]; //0 based index so -1
                                  //steps will be stored here
    }
};

int main()
{
    vector<int> KnightPos(2);
    vector<int> TargetPos(2);
    int n;
    cin >> n;
    cin >> KnightPos[0] >> KnightPos[1];
    cin >> TargetPos[0] >> TargetPos[1];

    Solution ob;
    int ans = ob.minStepToReachTarget(KnightPos, TargetPos, n);
    cout << ans << "\n";
    return 0;
}