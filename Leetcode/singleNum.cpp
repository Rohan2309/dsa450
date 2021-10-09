/*
136. Single Number
Easy

7420

249

Add to List

Share
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &v)
{
    if (v.size() == 1)
    {
        return v[0];
    }
    int n = v.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {                     //when same elements ar xor with each other result is 0
        res = res ^ v[i]; //0 xor with an element will return that element as answer
    }                     //elements appearing twice will cancel out and become 0 and only the single element will be in res
    return res;
}

int main()
{

    return 0;
}