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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
