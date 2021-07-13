/*
Longest Increasing Subsequence 
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        int dp[n + 1];
        dp[0] = INT_MIN;             //first element int min
        for (int i = 1; i <= n; i++) //rest element int max
        {
            dp[i] = INT_MAX;
        }
        for (int i = 0; i < n; i++)
        {
            int idx = upper_bound(dp, dp + n + 1, a[i]) - dp; //searching next greater element than a[i] in whole dp (-dp to get index)
            if (a[i] > dp[idx - 1] and a[i] < dp[idx])
            {
                dp[idx] = a[i]; //putting new element by replacing if its's smaller than prev element
            }
        }
        int m = 0;
        for (int i = n; i >= 0; i--) //loop backwards
        {
            if (dp[i] != INT_MAX)
            {
                m = i;
                break;
            }
        }
        return m;
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