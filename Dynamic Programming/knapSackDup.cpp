/*
Knapsack with Duplicate Items 
Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of the N items any number of times so that the total weight is less than or equal to W.

 

Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    int solve(int i, int j, int val[], int wt[])
    {
        if (i <= -1) // array ended
        {
            return 0;
        }
        if (dp[i][j] != -1) //memeset
        {
            return dp[i][j];
        }
        if (wt[i] > j) //if weight is greater than available weight
        {
            return dp[i][j] = solve(i - 1, j, val, wt); //skipping
        }
        //if not then 2 cases
        int case1 = val[i] + solve(i, j - wt[i], val, wt); //taking value
        int case2 = solve(i - 1, j, val, wt);              //not taking value
        return dp[i][j] = max(case1, case2);
    }

    int
    knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        dp[N][W];
        memset(dp, -1, sizeof(dp));
        return solve(N - 1, W, val, wt);
    }
};

int main()
{
    int n, w;
    cin >> n >> w;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    Solution ob;
    cout << ob.knapSack(n, w, val, wt) << endl;

    return 0;
}