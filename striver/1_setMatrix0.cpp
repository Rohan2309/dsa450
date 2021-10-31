/*
73. Set Matrix Zeroes
Medium

4933

430

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


*FIRST APPROACH*
traverse the matrix
if we find 0, set whole row and whole col as -1, if it is 1, if 0 then skip
then again traverse, convert all -1 to 0

*SECOND APPROACH*
take 2 dummy arrays, of size m and n
traverse matrix, if there is 0, set 0 in arrays of that pos

then again traverse matrix if any of the arrays of that pos is 0 then turn to 0 in matrix

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//THIRD APPROACH
    void setZeroes(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        int col = 1; //flag (first it is true)

        //treating first row and first colums as dummy arrays

        for(int i=0; i<r; i++){
            if(m[i][0]==0){//if any of the values in first col is zero
                col=0;//flag is false
                //later if it is 0 the whole 0th col will set to 0
            }
            /*
            reason for this is, if already 1st col is set to 0s,
            then 1st row will be set to 0. (we don't want that)
            */
            for(int j=1; j<c; j++){//we don't check col 1
                if(m[i][j]==0){
                    //filly dummy arrays with 0
                    m[i][0]=m[0][j]=0;//setting leftmost and topmost as 0
                }
            }
        }
        //linearly traverse from backwards
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=1; j--){
                //checking the dummy arrays
                if(m[i][0]==0 or m[0][j]==0){//checking if pos of first row and col is 0
                    m[i][j]=0;//changing to 0
                }
            }
            if(col==0){ //at the last, so it does not hampers the 1st row
                m[i][0]=0;//whole 0th col set to 0
            }
        }
    }
};


int main(){
    return 0;
}