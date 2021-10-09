/*
217. Contains Duplicate
Easy

2597

886

Add to List

Share
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &v)
{
    int n = v.size();
    bool f = false;
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            f = true;
        }
    }
    return f;
}

int main()
{

    return 0;
}