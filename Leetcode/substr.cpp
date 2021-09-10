/*
28. Implement strStr()
Easy

2903

2746

Add to List

Share
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{

    int m = haystack.size(), n = needle.size();
    for (int i = 0; i <= m - n; i++)
    {              //loop for haystack
        int j = 0; //reinitialized to 0
        for (j; j < n; j++)
        { //loop for needle
            if (haystack[i + j] != needle[j])
            { //invalid case
                break;
            }
        }
        if (j == n)   //when j size is complete
        {             //valid case
            return i; //return pos (first index)
        }
    }
    return -1;
}

int main()
{

    return 0;
}