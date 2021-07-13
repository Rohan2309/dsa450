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
        int dp[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1; //memset 1
        }
        for (int i = 1; i < n; i++) //checking from second element to last
        {
            for (int j = 0; j < i; j++) //checking elements from first till before i
            {
                if (a[j] < a[i]) //if elements prev to i are strictly smaller than 8i
                {
                    dp[i] = max(dp[i], dp[j] + 1); //first every element is set to 1, so if small we incre by 1 and take max
                }
            }
        }
        int m = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            m = max(m, dp[i]); //taking max from the new array formed
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