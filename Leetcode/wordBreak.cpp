/*
139. Word Break
Medium

8431

389

Add to List

Share
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[301]; // dp array
    // will return 1 or 0, i is the position we are standing on
    int helper(int i, string s, set<string> &wordDict)
    {
        int n = s.size();
        if (i == n)
        { // we reached the end
            return 1;
        }

        string tmp; // temporary var
        if (dp[i] != -1)
        { // memoisation
            return dp[i];
        }
        for (int j = i; j < n; j++)
        {
            tmp += s[j];
            if (wordDict.find(tmp) != wordDict.end())
            {                                   // temp is present in dictionary
                if (helper(j + 1, s, wordDict)) // the next character will be start of the helper func
                {
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0; // if no true
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st;
        memset(dp, -1, sizeof(dp));
        for (auto a : wordDict)
        { // having everything inside set
            st.insert(a);
        }
        return helper(0, s, st);
    }
};

int main()
{

    return 0;
}