/*
Palindrome String

Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
 
*/

#include <bits/stdc++.h>
using namespace std;

void ispalindrome(string s)
{
    int leftptr = 0;
    int rightptr = s.size() - 1;
    while (leftptr < rightptr)
    {
        if (s[leftptr++] != s[rightptr--])
        {
            printf("%s is Not Palindrom", s);
            return;
        }
    }
    printf("%s is palindrome", s);
}

int main()
{
    string str = "madam";
    string str2 = "rohan";
    ispalindrome(str);
    ispalindrome(str2);
    return 0;
}