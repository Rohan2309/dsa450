/*
36. Valid Sudoku
Medium

3374

612

Add to List

Share
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/

#include <bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int blocks[3][3][9] = {0};
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if (board[r][c] != '.')
            {                                //skip all number '.'
                int idx = board[r][c] - '1'; //calculate the number's index(board's number minus 1)
                if (rows[r][idx]++)          //if the number has already appeared once, return false.
                {
                    return 0;
                }

                if (cols[c][idx]++)
                {
                    return 0;
                }

                if (blocks[r / 3][c / 3][idx]++)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}
int main()
{

    return 0;
}