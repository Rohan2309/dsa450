#include <bits/stdc++.h>
using namespace std;


int f(int idx,int n, vector<int>& v, vector<vector<int>>&dp){
     if(idx==0)return n*v[0];
     int take = INT_MIN;//max pricing so initially int min
     if(~dp[idx][n])return dp[idx][n];
	 int notTake = f(idx-1,n,v,dp);
	 int rodL = idx+1;//0 based indexing
	 if(rodL<=n) take = v[idx] + f(idx,n-rodL,v,dp);
     return dp[idx][n] = max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n, vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
