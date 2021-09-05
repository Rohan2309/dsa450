/*
11. Container With Most Water
Medium

11526

772

Add to List

Share
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &a)
{
    int n = a.size();
    //two pointer
    int low = 0;
    int high = n - 1;
    int h1;
    int h2;
    int ans = INT_MIN;
    while (low <= high)
    { //loop
        h1 = a[low];
        h2 = a[high];
        int breadth = high - low;
        int minHeight = min(h1, h2);    //minimum of two
        int area = minHeight * breadth; //taking area
        ans = max(ans, area);           //updating if max
        //checking all cases
        if (h1 < h2)
        {
            low++;
        }
        else if (h2 <= h1)
        {
            high--;
        }
    }
    return ans;
}

int main()
{

    return 0;
}