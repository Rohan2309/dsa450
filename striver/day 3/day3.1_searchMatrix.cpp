/*
74. Search a 2D Matrix
Medium

4978

225

Add to List

Share
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ans = false;
        int i=0, j=m-1; //pointer standing at first row and last col
        
        //traversing till we get out of bound
        while(i<n and j>=0){ //since we are going left from the cols, j might get smaller than 0
            //since we are going down for the rows , so i might increase than n
            if(matrix[i][j]==target){
                ans = true;
            }
            if(matrix[i][j]>target){//if target is smaller we will always go left
                j--;
            }
            else{//if target is larger we will go down
                i++;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}