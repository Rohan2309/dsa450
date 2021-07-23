/*
Longest subsequence-1 
Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.


Example 1:

Input: N = 7
A[] = {10, 9, 4, 5, 4, 8, 6}
Output: 3
Explaination: The three possible subsequences 
{10, 9, 8} , {4, 5, 4} and {4, 5, 6}.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
        int dp[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1; //1 as ans will atleast be 1
        }
        dp[0] = 1;
        for (int i = 1; i < n; i++) //from 1 to n
        {
            for (int j = 0; j < i; j++) //0 to i
            {
                if (abs(a[i] - a[j]) == 1) //if difference is 1
                {
                    dp[i] = max(dp[i], dp[j] + 1); //taking max length
                }
            }
        }
        int ma = 0;
        for (int i = 0; i < n; i++)
        {
            ma = max(ma, dp[i]);
        }
        return ma;
    }
};
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution ob;
    cout << ob.longestSubsequence(n, a) << endl;
    return 0;
}