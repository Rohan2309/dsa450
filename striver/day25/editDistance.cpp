#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rec(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i<0)return j+1;//if 1st string gets over inserting all char left of string 2
        if(j<0)return i+1;//vice versa
        if(dp[i][j]!=-1)return dp[i][j];//memoise
        if(s[i]==t[j]) return  dp[i][j]=rec(i-1,j-1,s,t,dp);//if matches no operations
        //if does not match we take min of 3 operations
        return dp[i][j]=1+min(rec(i-1,j,s,t,dp),min(rec(i,j-1,s,t,dp),rec(i-1,j-1,s,t,dp)));
    }
public:
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return rec(n-1,m-1,w1,w2,dp);//start from end of str
    }
};

class Solution {
    int rec(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i==0)return j;//if 1st string gets over inserting all char left of string 2
        if(j==0)return i;//vice versa
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1]) return  dp[i][j]=rec(i-1,j-1,s,t,dp);//if matches no operations
        //if does not match we take min of 3 operations
        return dp[i][j]=1+min(rec(i-1,j,s,t,dp),min(rec(i,j-1,s,t,dp),rec(i-1,j-1,s,t,dp)));
    }
public:
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return rec(n,m,w1,w2,dp);//start from end of str
    }
};
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));//shifting idx
        for(int i=0; i<=n; ++i) dp[i][0] = i;//for any j=0
        for(int j=0; j<=m; ++j) dp[0][j] = j;//for any i=0
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1]==t[j-1])   dp[i][j]=dp[i-1][j-1];//if matches no operations
        //if does not match we take min of 3 operations
                else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
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
