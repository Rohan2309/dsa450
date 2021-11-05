/*
48. Rotate Image
Medium

6821

416

Add to List

Share
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Example 3:

Input: matrix = [[1]]
Output: [[1]]
Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]


123       741
456   ->  852
789       963

1st approach, use another matrix, take the first row put it in the last col
take the 2nd row put it in the 2nd last col

optimal approach,
first, transpose (cols will become rows and rows will become cols)


123       147
456   ->  258
789       369

now reverse every row of the matrix

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int r = m.size();
        //transpose matrix
        for(int i=0; i<r; i++){//every row
            for(int j=0; j<i; j++){//0 to i
                swap(m[i][j], m[j][i]);
            }
        }
        //reverse row
        for(int i=0; i<r; i++){//every row traverse
            reverse(m[i].begin(), m[i].end());//rev
        }
    }
};

int main(){
    return 0;
}