
/*
171. Excel Sheet Column Number
Easy

2056

224

Add to List

Share
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
Example 4:

Input: columnTitle = "FXSHRXW"
Output: 2147483647


*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int base = 26; // A to Z is 1 to 26
        int ans = 0;
        for(char c: columnTitle){ //every character through string
            int d = c - 'A' + 1; // for A it will be 0, so we add 1
            ans = ans*base + d;
        }
        return ans;
    }
};

int main()
{

    return 0;
}