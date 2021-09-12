/*
34. Find First and Last Position of Element in Sorted Array
Medium

7168

235

Add to List

Share
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &a, int x)
{
    vector<int> ans;
    int n = a.size();
    if (n == 0)
    {
        return {-1, -1};
    }
    vector<int>::iterator it;
    it = std::find(a.begin(), a.end(), x); //finding even the target value is present or not
    if (it == a.end())
    { //if we have reached the end then we have not found
        return {-1, -1};
    }
    //we have target
    vector<int>::iterator lower, upper; //creating two iterators
    lower = lower_bound(a.begin(), a.end(), x);
    upper = upper_bound(a.begin(), a.end(), x);
    ans.push_back(lower - a.begin()); //-a.begin() for index
    ans.push_back(upper - a.begin() - 1);
    return ans;
}
int main()
{

    return 0;
}