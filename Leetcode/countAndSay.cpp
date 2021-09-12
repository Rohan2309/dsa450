/*

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

    return 0;
}