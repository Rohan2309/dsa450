/*
125. Valid Palindrome
Easy

2434

4330

Add to List

Share
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    if (s.size() <= 1)
    {
        return true;
    }
    int leftPtr = 0;
    int rightPtr = s.size() - 1;
    bool flag = true;
    while (leftPtr < rightPtr)
    {
        //we will only compare characters
        while (leftPtr < rightPtr and !isalnum(s[leftPtr]))
        {              //skipping alphanumeric chars
            leftPtr++; //for left ptr
        }
        while (leftPtr < rightPtr and !isalnum(s[rightPtr]))
        {
            rightPtr--; //for right ptr
        }
        //checking only after converting to lowercase
        if (leftPtr < rightPtr and tolower(s[leftPtr++]) != tolower(s[rightPtr--]))
        { //false case
            flag = false;
        }
    }
    return flag;
}

int main()
{

    return 0;
}