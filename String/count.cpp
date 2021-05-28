/*
Count and Say
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted
 into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is
 a contiguous section all of the same character. Then for each group, say the number of characters, then say
  the character. To convert the saying into a digit string, replace the counts with a number and concatenate
   every saying.

For example, the saying and conversion for digit string "3322251":

Given a positive integer n, return the nth term of the count-and-say sequence.

 

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
*/

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if (n == 1) //base case
    {
        return "1";
    }
    if (n == 2) //base case
    {
        return "11";
    }
    string s = "11";
    for (int i = 3; i <= n; i++)
    {
        string t = ""; //will have ans of next value of i
        s = s + '$';   //delimeter (checks last value)
        int count = 1; //every number will have atleast 1 counter
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] != s[j - 1]) //not equal
            {
                t = t + to_string(count); //storing no of count of number
                t = t + s[j - 1];         //storing which number
                count = 1;                //reset
            }
            else
            {
                count++; //s[j]==s[j-1]
            }
        }
        s = t; //storing t in s so that with help of s we can get ans of new ith value
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
    return 0;
}