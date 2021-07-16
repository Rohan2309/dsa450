/*
Minimum cost to fill given weight in a bag 
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Example 1:

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int dp[1001][1001]; // n , w (n is array and w is weight )

    int func(int a[], int n, int w)
    {                           //base cases
        if (n == -1 and w == 0) //we reached starting point and ans forms in between
        {
            return 0;
        }
        //if this case is false
        if (n == -1) //we reached start ans ans is not formed
        {
            return 1e9;
        }
        if (w == 0) //weight 0 in middle
        {
            return 0;
        }
        if (dp[n][w] != -1) //memoisation
        {
            return dp[n][w];
        }
        //n+1 is weight of current element
        if ((n + 1) > w or a[n] == -1)
        {
            return dp[n][w] = func(a, n - 1, w); //we are not taking than element
        }
        //if this case is not happening
        int y = func(a, n - 1, w);              //not taking
        int x = a[n] + func(a, n, w - (n + 1)); //taking value
        return dp[n][w] = min(x, y);
    }

    int minimumCost(int cost[], int N, int W)
    {
        // Your code goes here
        memset(dp, -1, sizeof(dp));
        int x = func(cost, N - 1, W);
        if (x >= 1e9)
        {
            return -1;
        }
        else
        {
            return x;
        }
    }
};

int main()
{
    int n, w;
    cin >> n >> w;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution ob;
    cout << ob.minimumCost(a, n, w) << endl;
    return 0;
}