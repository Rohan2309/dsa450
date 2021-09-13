/*
69. Sqrt(x)
Easy

2527

2632

Add to List

Share
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*/

#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    // long long y=0;
    // while(y*y<=x){
    //     y++;
    // }
    // return y-1;
    long long start = 0;
    long long end = INT_MAX;
    long ans = 0;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (mid * mid <= x)
        {                    //wont stop here
            ans = mid;       //prliminary ans
            start = mid + 1; //checking next digits
        }
        else
        { //if false
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}