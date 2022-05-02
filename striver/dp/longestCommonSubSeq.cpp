#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //base cases by shifting 1 right
        for(int i=0;i<=n;++i)dp[i][0]=0; //0 treated as -1
        for(int j=0;j<=m;++j)dp[0][j]=0;
        //recursion bottom up
        for(int i=1; i<=n; ++i){//i=0 is base
            for(int j=1; j<=m; ++j){
                if(s[i-1]==t[j-1])  dp[i][j] = 1 + dp[i-1][j-1];//i-1 is treated as i
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
