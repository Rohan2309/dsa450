#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i<0 or j<0) return 0;//base
        if(dp[i][j]!=-1)return dp[i][j];//memoisation
        if(s[i]==t[j])return dp[i][j]= 1+ f(i-1,j-1,s,t,dp);//if matches + 1 and shift to prev idx of both
        return dp[i][j]= max(f(i-1,j,s,t,dp), f(i,j-1,s,t,dp));//if does not match take only 1 which gives max
    }
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return f(n-1, m-1, s, t, dp);//taking from last index
    }
};
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        //shifting to left cause we can't take -1 in base case
        //tretaing -1 as 0
        for(int i=0; i<=n; ++i)dp[i][0]=0;//base cases
        for(int j=0; j<=m; ++j)dp[0][j]=0;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1]==t[j-1]) dp[i][j]= 1+ dp[i-1][j-1];//if matches + 1 and shift to prev idx of both
        else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);//if does not match take only 1 which gives max
            }
        }
        return dp[n][m];//taking from last index
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
