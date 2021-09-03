/*
7. Reverse Integer
Easy

5551

8291

Add to List

Share
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    long int ans = 0;
    if (x >= 2147483647 or x <= -2147483648)
    { //within the range of signed 32-bit integer range
        return 0;
    }
    if (x > 0)
    { //when positive
        while (x > 0)
        {
            ans = ans * 10;
            if (ans >= 2147483647 or ans <= -2147483648)
            { //within the range of signed 32-bit integer range
                return 0;
            }
            ans = ans + (x % 10);
            x = x / 10;
        }
    }
    else
    {               //when negative
        x = -1 * x; //negative value converts to positive
        while (x > 0)
        {
            ans = ans * 10;
            if (ans >= 2147483647 or ans <= -2147483648)
            { //in the range of signed 32-bit integer range
                return 0;
            }
            ans = ans + (x % 10);
            x = x / 10;
        }
        ans = -1 * ans; //positive value to negative
    }
    return int(ans);
}
int main()
{

    return 0;
}