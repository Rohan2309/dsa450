/*
73. Set Matrix Zeroes
Medium

4608

411

Add to List

Share
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &m)
{
    int r = m.size();
    int c = m[0].size();
    int col = 1; //flag
    for (int i = 0; i < r; i++)
    {
        if (m[i][0] == 0)
        {            //if any of the values in first col is zero
            col = 0; //flag is false
            //later if it is 0 the whole 0th col will set to 0
        }
        for (int j = 1; j < c; j++)
        { //we don't check col 1
            if (m[i][j] == 0)
            {
                m[i][0] = m[0][j] = 0; //setting leftmost and topmost as 0
            }
        }
    }
    //linearly traverse from backwards
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c - 1; j >= 1; j--)
        {
            if (m[i][0] == 0 or m[0][j] == 0)
            {                //checking if pos of first row and col is 0
                m[i][j] = 0; //changing to 0
            }
        }
        if (col == 0)
        {
            m[i][0] = 0; //whole 0th col set to 0
        }
    }
}

int main()
{

    return 0;
}