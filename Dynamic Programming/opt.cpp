/*
Optimal Strategy For A Game 
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(int i, int j, int a[])
{
    if (i > j) //base
    {
        return 0;
    }
    if (dp[i][j] != -1) //memoisation
    {
        return dp[i][j];
    }
    int x, y;
    //if i take i then opponent has opt from i+1 to j
    //opponest will give me minimum of i+1 or j
    x = a[i] + min(solve(i + 2, j, a), solve(i + 1, j - 1, a));
    //if i take j then opponent has opt from i and j-1
    //opponest will give me minimum of i and j-1
    y = a[j] + min(solve(i + 1, j - 1, a), solve(i, j - 2, a));
    return dp[i][j] = max(x, y);
}

long long maximumAmount(int arr[], int n)
{
    // Your code here
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    return solve(0, n - 1, arr);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maximumAmount(a, n) << endl;

    return 0;
}