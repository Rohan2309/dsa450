/*
3. Longest Substring Without Repeating Characters
Medium

17089

814

Add to List

Share
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> mp;
    int n = s.size();
    int left = 0;
    int len = 0;
    for (int right = 0; right < n; right++)
    { //looping through all elements
        if (mp.find(s[right]) != mp.end())
        {                                       //if already element is present in map
            left = max(left, mp[s[right]] + 1); //left pointer will be right side of the element thus +1
        }
        //else when element is not present
        mp[s[right]] = right;             //updating new pos of element
        len = max(len, right - left + 1); //longest
    }
    return len;
}
int main()
{

    return 0;
}