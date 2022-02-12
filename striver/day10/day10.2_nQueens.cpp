/*
51. N-Queens
Hard

5108

143

Add to List

Share
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]

*/

#include <bits/stdc++.h>
using namespace std;
/*
Backstracking approach

class Solution {
public:
    bool check(int r, int c, vector<string>&v, int n){
        //we only check upper diagonal, left and lower diagona
        //as we move from left to right
        int r1=r,c1=c;
        
        //for upper diagonal
        while(r>=0 and c>=0){
            if(v[r][c]=='Q')return false;
            r--;c--;
        }
        //for left
        r=r1;c=c1;//re-init val
        while(c>=0){
            if(v[r][c]=='Q')return false;
            c--;
        }
        
        //for lower diagonal
        r=r1;c=c1;//re-init val
        while(r<n and c>=0){
            if(v[r][c]=='Q')return false;
            c--;r++;
        }
        return true;
    }
    
    void helper(int c, vector<string>&v, int n, vector<vector<string>>&ans){
        if(c==n){//base case when at last col
            ans.emplace_back(v);
            return;
        }
        for(int r=0; r<n;++r){
            if(check(r,c,v,n)){
                v[r][c]='Q';
                helper(c+1,v,n,ans);//for the next col
                v[r][c]='.';//backstracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>v(n);
        string s(n,'.');//empty strings of sz n
        for(int i=0; i<n;++i)v[i]=s;//inserting n empty strings in vector
        helper(0,v,n,ans);//init at 0 col
        
        return ans;
    }
};

*/

//Backstracking approach (hashing)
class Solution {
  public:
    void solve(int c, vector < string > & v, vector < vector < string >> & ans, vector < int > & lr, vector < int > & ud, vector < int > & ld, int n) {
      if (c == n) {//base case when at last col
        ans.emplace_back(v);
        return;
      }
      for (int r = 0; r < n; ++r) {
        if (lr[r] == 0 && ld[r + c] == 0 && ud[n - 1 + c - r] == 0) {
          v[r][c] = 'Q';
          lr[r] = 1;//conds for diff directions
          ld[r + c] = 1;
          ud[n - 1 + c - r] = 1;
          solve(c + 1, v, ans, lr, ud, ld, n);//for the next col
          v[r][c] = '.';//backstracking
          lr[r] = 0;
          ld[r + c] = 0;
          ud[n - 1 + c - r] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > v(n);
      string s(n, '.');//empty strings of sz n
      for (int i = 0; i < n; i++)v[i]=s;//inserting n empty strings in vector
      vector < int > lRow(n, 0);//left row
      vector < int > uDiag(2 * n - 1, 0);//upper  diagonal
      vector < int > lDiag(2 * n - 1, 0);//lower diagonal
      solve(0, v, ans, lRow, uDiag, lDiag, n);//init at 0 col
      return ans;
    }
};

int main()
{
    
    return 0;
}