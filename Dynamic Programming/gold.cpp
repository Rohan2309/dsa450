/*
Gold Mine Problem

Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect. 
Examples: 
 

Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m = 4, n = 4;
    int gold[m][n] = {{1, 3, 1, 5},
                      {2, 2, 4, 1},
                      {5, 0, 2, 3},
                      {0, 6, 1, 2}};

    //starting from second last column
    for (int col = n - 2; col >= 0; col--)
    {
        for (int row = 0; row < m; row++)
        {
            int right, right_up, right_down;
            right = gold[row][col + 1];
            right_up = (row == 0) ? 0 : gold[row - 1][col + 1];                      //if 1st row then can't go up
            right_down = (row == m - 1) ? 0 : gold[row + 1][col + 1];                //if last row then can't go down
            gold[row][col] = gold[row][col] + max(right, max(right_up, right_down)); //adding max of 3
        }
    }
    //table is updated
    //first col has max ans
    int res = gold[0][0];       //taking first value
    for (int i = 1; i < m; i++) //loop from second row
    {
        res = max(res, gold[i][0]); //storing max in res
    }
    cout << res;
}

int main()
{
    solve();
    return 0;
}