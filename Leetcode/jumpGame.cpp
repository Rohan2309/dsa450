/*
55. Jump Game
Medium

7724

475

Add to List

Share
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &v)
{
    int n = v.size();

    int maxReach = 0; //max reachable point
    for (int i = 0; i < n; i++)
    {
        if (maxReach < i)
        { //when i pointer shifts but max reachable point is not >= i, it can't reach i
            return false;
        }
        else
        {
            maxReach = max(maxReach, i + v[i]); //maximum reachable point
        }
    }
    return true; //we have processed all the index
}

int main()
{

    return 0;
}