/*
Coin Change

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //first form tree
    //from back of array
    //like sum is 10 and array consits 2,5,3,6
    //take 6 like in back from array subtract it from 10 once and once don't subtract
    //then do same with 5 see all possible solution when subtraction results to 0
    long long int dp[1000][1000]; //const given 10^3

    long long int solve(int a[], int m, int n)
    {                          //base case
        if (m == -1 and n > 0) //if array's size ends or n number is not formed
        {
            return 0; //not valid
        }
        if (n == 0) // n becomes 0 (number formed)
        {
            return 1; //valid, answer forming
        }
        if (n < 0) //invalid sequence becomes negative
        {
            return 0;
        }
        if (dp[n][m] != -1) //memoisation
        {                   //if something is already stored in dp and it occurs again return that
            return dp[m][n];
        }
        //else we are taking the number from back once
        //and not taking it and seeing resultant
        return dp[m][n] = solve(a, m, n - a[m]) + solve(a, m - 1, n);
        //first time we are not decreasing index but decreasing sum
        //second time we doing vice versa
    }

    long long int count(int a[], int m, int n)
    {
        //code here.
        dp[m][n + 1]; //resizing dp size
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1; //setting each value of dp with -1
            }
        }
        return solve(a, m - 1, n); //array, last index, sum
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    cout << ob.count(arr, m, n) << endl;
    return 0;
}