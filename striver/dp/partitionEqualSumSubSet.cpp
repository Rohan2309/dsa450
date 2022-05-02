#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool f(vector<int>& v, int idx, int t,vector<vector<int>>&dp){
        if(t==0)return true;//when target becomes 0
        if(idx==0)return (v[0]==t);//when at last index and target == it's value
        if(~dp[idx][t])return dp[idx][t];
        bool notTake = f(v,idx-1,t,dp);
        bool take = false;
        if(t>=v[idx]) take = f(v,idx-1,t-v[idx],dp);
        return dp[idx][t]=(take or notTake);//or of both possibilities
    }
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum =0;
        for(int i=0;i<n;++i)sum+=v[i];
        if(sum%2!=0)return false;
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(v,n-1,target,dp);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
