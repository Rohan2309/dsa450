/*
Maximum Sum Square SubMatrix
Medium

99

2

Add to favorites
Asked In:
DE SHAW
Problem Description

Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all the elements in submatrix is maximum.



Problem Constraints
1 <= N <= 103.

1 <= B <= N 

-102 <= A[i][j] <= 102.



Input Format
First arguement is an 2D integer matrix A.

Second argument is an integer B.



Output Format
Return a single integer denoting the maximum sum of submatrix of size B x B.



Example Input
Input 1:

 A = [
        [1, 1, 1, 1, 1]
        [2, 2, 2, 2, 2]
        [3, 8, 6, 7, 3]
        [4, 4, 4, 4, 4]
        [5, 5, 5, 5, 5]
     ]
 B = 3
Input 2:

 A = [
        [2, 2]
        [2, 2]
    ]
 B = 2


Example Output
Output 1:

 48
Output 2:

 8


Example Explanation
Explanation 1:

    Maximum sum 3 x 3 matrix is
    8 6 7
    4 4 4
    5 5 5
    Sum = 48
Explanation 2:

 Maximum sum 2 x 2 matrix is
  2 2
  2 2
  Sum = 8


*/

#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int> > &A, int B) {
    int n =A.size();//no of rows
    int m =A[0].size();//no of columns
    int ans = INT_MIN;
    int dp[n+1][m+1];//dp
    //filling dp matrix with sum values till that ele
    //start from 1 as first row and col will be 0
    for(int i=1; i<n+1; ++i){
        for(int j=1; j<m+1;++j){
            //taking and ele above , taking an ele left and removing diag ele as it came twice
            dp[i][j]=A[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            //A[i-1][j-1] because matrix starts from 1
        }
    }
    for(int i=1; i<n+1; ++i){
        for(int j=1; j<m+1;++j){
            int s= INT_MIN;
                //checker so it doesnt exceeds
            if(i-B>=0 and j-B>=0){
                //detaching matrix
                //subtracting left from last ele, subtracting top from last ele
                //adding dia because subtracted 2 times
                s=dp[i][j]-dp[i-B][j]-dp[i][j-B]+dp[i-B][j-B];
                ans= max(ans,s);

            }
            
        }
    }
    return ans;
}


int main() {
    return 0;
}
