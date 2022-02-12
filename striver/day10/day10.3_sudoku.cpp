/*
37. Sudoku Solver
Hard

4558

144

Add to List

Share
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>&b, int r, int c, char x){
        for(int i=0; i<9;++i){
            if(b[i][c]==x)return false;//for rows
            if(b[r][i]==x)return false;//for cols
            if(b[3*(r/3)+i/3][3*(c/3)+i%3]==x)return false; //for each boxes
        }
        return true;
    }
    bool solve(vector<vector<char>>&b){
        int n = b.size();
        int m = b[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(b[i][j]=='.'){//if empty
                    for(char c = '1'; c<='9'; ++c){//trying every posibility from 1 to 9
                      if(check(b,i,j,c)){
                          b[i][j]=c;//filling with that char
                          if(solve(b))return true;//if true then it finds next possible guy
                          else b[i][j]='.';//if false then backstrack
                      }  
                    }
                    //not able to put anyone in empty location
                    return false;
                }
            }
        }
        //never getting an empty cell
        return true;
    }
    void solveSudoku(vector<vector<char>>& b) {
        solve(b);
    }
};
int main()
{
    
    return 0;
}