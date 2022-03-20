/*
5. Longest Palindromic Substring
Medium

16612

974

Add to List

Share
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
        {
            return s;
        }
        int n = s.size();
        int maxLen = INT_MIN;

        int st = 0, en = 0; // to get the actual substring
        int l, r;           // pointers

        // for odd part
        for (int i = 0; i < n - 1; i++)
        {
            l = r = i;
            while (l >= 0 and r < n) // boundary conditions
            {
                if (s[l] == s[r])
                {
                    l--;
                    r++;
                }
                else
                { // when unequal
                    break;
                }

                int len = r - l - 1;
                if (len > maxLen)
                {
                    maxLen = len;
                    st = l + 1; // will keep track of prev value
                    en = r - 1;
                }
            }
        }
        // for even part
        for (int i = 0; i < n - 1; i++)
        {
            l = i;
            r = i + 1;
            while (l >= 0 and r < n)
            {
                if (s[l] == s[r])
                {
                    l--;
                    r++;
                }
                else
                { // when unequal
                    break;
                }

                int len = r - l - 1;
                if (len > maxLen)
                {
                    maxLen = len;
                    st = l + 1; // will keep track pof prev value
                    en = r - 1;
                }
            }
        }

        return s.substr(st, maxLen);
    }
};

int main()
{

    return 0;
}