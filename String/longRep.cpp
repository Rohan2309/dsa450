/*
Longest Repeating Subsequence
Given a string, find the length of the longest repeating subsequence such that the two subsequences don't have same string character at the same position, i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.

 

Example 1:

Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".
Example 2:

Input: str = "aab"
output: 1
Explanation: The longest reapting subsequenece
is "a".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        int n = str.length();
        int dp[n + 1][n + 1]; //dp array
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 or j == 0)
                { //base case
                    dp[i][j] = 0;
                }
                else if (str[i - 1] == str[j - 1] and i != j)
                { //valid case
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //1st check upto i's prev value and then j's prev val
                }
            }
        }
        return dp[n][n];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str;
    cin >> str;

    Solution ob;
    int ans = ob.LongestRepeatingSubsequence(str);
    cout << ans << endl;

    return 0;
}