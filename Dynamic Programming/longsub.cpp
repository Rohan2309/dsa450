/*
Longest Common Subsequence 
Medium Accuracy: 49.98% Submissions: 38434 Points: 4
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.

    int dp[1001][1001];

    int func(int x, int y, string s1, string s2)
    {

        //base case
        if (x == -1 or y == -1)
        {
            return 0;
        }
        //memoisation
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }
        if (s1[x] == s2[y]) //if matches
        {
            return dp[x][y] = 1 + func(x - 1, y - 1, s1, s2); //increasing counter +1
            //and sending both back by 1 step
        }

        int a = func(x - 1, y, s1, s2); //1st taking x back and y same
        int b = func(x, y - 1, s1, s2); //2nd taking y back and x same

        //as it said lcs then we take maximum value
        return dp[x][y] = max(a, b);
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int m = sizeof(dp);
        memset(dp, -1, m);
        return func(x - 1, y - 1, s1, s2); //-1 as we are taking from back of s
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    string s1, s2;
    cin >> s1 >> s2;
    Solution ob;
    cout << ob.lcs(x, y, s1, s2) << endl;
    return 0;
}