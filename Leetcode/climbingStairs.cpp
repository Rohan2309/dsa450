/*
70. Climbing Stairs
Easy

8088

238

Add to List

Share
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    //like fibonacci series
    if (n <= 2)
    { //when 1 we have 1 , when 2 we have 2
        return n;
    }
    //for every value of n in ans we add n-1 and n-2, like for 3 we add ans of 2 amnd 1
    int x = 1; //begining
    int y = 2;
    for (int i = 3; i <= n; i++)
    {                //3 to n
        int tmp = y; //temp var
        y = y + x;   //3
        x = tmp;     //2
    }
    return y; //3 when n is 3
}

int main()
{

    return 0;
}