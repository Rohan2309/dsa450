/*
LCS of three strings 
Medium Accuracy: 67.03% Submissions: 6941 Points: 4
Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:

Input:
A = "geeks", B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.
â€‹Example 2:

Input: 
A = "abcd", B = "efgh", C = "ijkl"
Output: 0
Explanation: There's no common subsequence
in all the strings.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[205][205][205];

int func(string A, string B, string C, int n1, int n2, int n3)
{
    //base case
    if (n1 == 0 or n2 == 0 or n3 == 0) //if any string ends
    {
        return 0;
    }
    if (dp[n1][n2][n3] != -1) //memoisation
    {
        return dp[n1][n2][n3];
    }
    if (A[n1 - 1] == B[n2 - 1] and B[n2 - 1] == C[n3 - 1]) //if all elements are equal
    {
        return dp[n1][n2][n3] = 1 + func(A, B, C, n1 - 1, n2 - 1, n3 - 1); //1 already in ans and rest of str lcs
    }
    else
    {
        int l, r, p; //checking 3 diff cases
        l = func(A, B, C, n1 - 1, n2, n3);
        r = func(A, B, C, n1, n2 - 1, n3);
        p = func(A, B, C, n1, n2, n3 - 1);
        return dp[n1][n2][n3] = max({p, l, r});
    }
}
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // your code here

    memset(dp, -1, sizeof(dp));
    return func(A, B, C, n1, n2, n3);
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    string A, B, C;
    cin >> A >> B >> C;
    cout << LCSof3(A, B, C, n1, n2, n3) << endl;

    return 0;
}