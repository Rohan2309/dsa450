#include <bits/stdc++.h>
using namespace std;

class Solution {
    int f(int idx, vector<int>& v, int t ,vector<vector<int>>&dp){
        if(idx==0)return (t%v[0]==0);//if last element of array can form the target, we return 1
        if (~dp[idx][t])  return dp[idx][t]; 
        int notTake = f(idx-1,v,t,dp);
        int take = 0;
        if(v[idx]<=t) take = f(idx,v,t-v[idx],dp);
        return dp[idx][t] = take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);    
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
