/*
62. Unique Paths
Medium

7190

269

Add to List

Share
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
*/

#include <bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
// #define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int> //max heap
#define pqs             priority_queue<int,vi,greater<int> > //min heap
#define setbits(x)      __builtin_popcountll(x)//gives number of setbits
#define zrobits(x)      __builtin_ctzll(x)//gives number of 0 bits
#define mod             1000000007// 1e9+7  ans%mod
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n]; //dynamic array
#define w(x)            int x; cin>>x; while(x--) //test case
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());//random shuffle

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //policy based ds

#define deb(x) cout << #x << " " << x << endl;//for debugging
#define fo(i, n) for(i=0; i<n; i++)
#define fo1(i,n) for(i=1; i<=n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)

#define vi vector<int>
#define vvi vector<vi>



class Solution {
public:
    /*
    brute force - recursion.
    optimal - dynamic programming
    */
    int solve(int i, int j, int n, int m, vector<vector<int>>&dp){
        if(i==(n-1)and j==(m-1)){ //if it reaches the last
            return 1;
        }
        if(i>=n or j>=m){//index out of bound
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            return dp[i][j] = solve(i+1, j, n, m, dp) + solve(i, j+1, n, m, dp); 
        }
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int> (n, -1)); //2d matrix initialized with -1
        int num = solve(0,0,m,n,dp);
        return num;
    }
};


int main()
{
    
    return 0;
}