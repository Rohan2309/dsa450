/*
Longest Palindromic Subsequence

As another example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subsequence in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.
The naive solution for this problem is to generate all subsequences of the given sequence and find the longest palindromic subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently be solved using Dynamic Programming.
1) Optimal Substructure: 
Let X[0..n-1] be the input sequence of length n and L(0, n-1) be the length of the longest palindromic subsequence of X[0..n-1]. 
If last and first characters of X are same, then L(0, n-1) = L(1, n-2) + 2. 
Else L(0, n-1) = MAX (L(1, n-1), L(0, n-2)). 
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(string s, int i, int j)
{ //i is start ponter and  j is end pointer
    if (i == j)
    {
        return 1;
    }
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] == s[j])
    {
        return dp[i][j] = solve(s, i + 1, j - 1) + 2; //adding 2 to ans as it is contributing 2 elements
    }
    //if not equal then 2 cases either i+1 or j-1
    return dp[i][j] = max(solve(s, i, j - 1), solve(s, i + 1, j));
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, n - 1);
    return 0;
}