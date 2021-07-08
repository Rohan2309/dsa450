/*
0 - 1 Knapsack Problem 

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];

    int solve(int wt[], int val[], int w, int n)
    {
        //base case
        if (w == 0 or n == -1) //if weight becomes 0, weigth limit reached and n=-1 when array ends
        {
            return 0;
        }
        if (dp[n][w] != -1) //memorization
        {
            return dp[n][w];
        }
        if (wt[n] > w) //we can't subtract as it is larger
        {
            return dp[n][w] = solve(wt, val, w, n - 1); //we will not subtract that weight so weight remains same
            //and array n-1
        }
        //now weight value if is lesser than w
        //will take 2 case
        int a, b;
        a = val[n] + solve(wt, val, w - wt[n], n - 1); //taking the value
        b = solve(wt, val, w, n - 1);                  // not taking value
        return dp[n][w] = max(a, b);                   //returning maximum value
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        dp[n][W];
        memset(dp, -1, sizeof(dp));
        return solve(wt, val, W, n - 1); // n-1 as we will iterate array from back
    }
};

int main()
{
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    Solution ob;
    cout << ob.knapSack(w, wt, val, n) << endl;

    return 0;
}