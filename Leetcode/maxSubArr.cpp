/*
53. Maximum Subarray
Easy

14415

680

Add to List

Share
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &a)
{
    int n = a.size();
    int curSum = 0;       //current sum
    int maxSum = INT_MIN; //max sum
    int i;                //iterator
    for (i = 0; i < n; i++)
    {
        curSum += a[i];
        if (curSum > maxSum)
        {
            maxSum = curSum;
        }
        if (curSum < 0)
        {
            curSum = 0;
        }
    }
    return maxSum;
}

int main()
{

    return 0;
}