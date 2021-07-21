/*
Friends Pairing Problem 
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1000000007;

    long long int func(int n, long long int dp[])
    {
        if (n <= 2) //base case
        {
            return n;
        }
        if (dp[n] != -1) //memoisation
        {
            return dp[n];
        }
        long long int a, b;
        //solo taking that element Solo
        a = func(n - 1, dp) % mod;
        //pairing
        b = (((n - 1) % mod) * func(n - 2, dp) % mod) % mod; //made pair with any of  n-1 and it will go to n-2 position
        return dp[n] = a + b;
    }

    int countFriendsPairings(int n)
    {
        // code here
        long long int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        return func(n, dp) % mod;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ob;
    cout << ob.countFriendsPairings(n) << endl;
    return 0;
}