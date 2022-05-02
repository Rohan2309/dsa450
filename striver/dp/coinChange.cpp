#include <bits/stdc++.h>
using namespace std;


class Solution {
    int f(int idx, vector<int>& v, int t ,vector<vector<int>>&dp){
        if(idx==0){//when last ele is reached check if target is divisible by it
            //return how many times
            if (t%v[0]==0) return t/v[0];
            return 1e9;//not possible
        }
        if (~dp[idx][t])  return dp[idx][t]; 
        int notTake = f(idx-1,v,t,dp);
        int take = 1e9;//if take it not possible assigning it to a large val
        if(v[idx]<=t) take = 1+f(idx,v,t-v[idx],dp);
        return dp[idx][t] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res = f(n-1,coins,amount,dp);
        if(res>=1e9)return -1;
        else return res;  
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
