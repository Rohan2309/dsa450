/*
Longest Palindrome in a String

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] 
where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is
 palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least
  starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
â€‹Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.
*/

#include <bits/stdc++.h>
using namespace std;

void printString(string s, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << s[i];
    }
}

void longestPal(string s)
{
    int low, high, start = 0, end = 1;
    for (int i = 1; i < s.length(); i++)
    {

        //even
        low = i - 1;
        high = i;
        while (low >= 0 and high < s.length() and s[low] == s[high])
        {
            if (high - low + 1 > end) //length of current substring is greater than the prev ones
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }

        //odd
        low = i - 1;
        high = i + 1; //will have a difference of 2 between them
        while (low >= 0 and high < s.length() and s[low] == s[high])
        {
            if (high - low + 1 > end) //length of current substring is greater than the prev ones
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }
    }
    printString(s, start, start + end - 1);
}

int main()
{
    string str = "aaaabbaa";
    longestPal(str);

    return 0;
}