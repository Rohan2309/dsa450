/*
42. Trapping Rain Water
Hard

13751

194

Add to List

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    int h1 = 0; //left maximum
    int h2 = 0; //right maximum
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] >= h1)
            {
                h1 = height[l];
            }
            else
            {
                ans += h1 - height[l];
            }
            l++;
        }
        else if (height[r] <= height[l])
        {
            if (height[r] >= h2)
            {
                h2 = height[r];
            }
            else
            {
                ans += h2 - height[r];
            }
            r--;
        }
    }
    return ans;
}

int main()
{

    return 0;
}