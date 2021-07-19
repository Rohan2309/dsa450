/*
Interleaved Strings 
Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

An interleaving of two strings S and T is a configuration where they are divided into non-empty substrings such that:

S = S1 + S2 + ... + SN
T = T1 + T2 + ... + TM
|N - M| <= 1
The interleaving is S1 + T1+ S2 + T2 + S3 + T3 + ... or T1 + S1+ T2 + S2 + T3 + S3 ...
Note: a + b is the concatenation of strings a and b.

Return true if C is formed by an interleaving of A and B, else return false.

Example 1:

Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    bool solve(string a, string b, string c, int n, int m, int o)
    {
        if (o == 0) //if c ends , means a and b both are used
        {
            return 1;
        }
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        int A, B;
        A = B = 0;
        if (n - 1 >= 0 and a[n - 1] == c[o - 1])
        {
            A = solve(a, b, c, n - 1, m, o - 1);
        }
        if (m - 1 >= 0 and b[m - 1] == c[o - 1])
        {
            B = solve(a, b, c, n, m - 1, o - 1);
        }
        return dp[n][m] = A or B; //taking thw one in which we are getting ans
    }
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C)
    {
        //Your code here
        int n = A.length();
        int m = B.length();
        int o = C.length();
        if (n + m != o)
        {
            return 0;
        }
        dp[n][m];
        memset(dp, -1, sizeof(dp));
        return solve(A, B, C, n, m, o);
    }
};

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    Solution ob;
    cout << ob.isInterleave(a, b, c) << endl;
    return 0;
}