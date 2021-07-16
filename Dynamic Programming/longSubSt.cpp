/*
Longest Common Substring 
Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n + 1][m + 1];
        int res = 0; //to take max value from matrix
                     //have to make first row and first col 0 as we rae checking with i-1 and j-1
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (S1[i - 1] == S2[j - 1]) //converting 1 based to 0 based
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1; //going to behind diagonal and adding 1
                    res = max(res, dp[i][j]);
                }
                //if not matches then 0
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    Solution ob;
    cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    return 0;
}