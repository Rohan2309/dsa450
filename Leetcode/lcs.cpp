/*
128. Longest Consecutive Sequence
Medium

7028

325

Add to List

Share
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    set<int> s; //hash set
    for (int i = 0; i < nums.size(); i++)
    { //inserting all elements in hashset
        s.insert(nums[i]);
    }
    int cnt = 0; //ans
    for (int i = 0; i < nums.size(); i++)
    {
        int tmp = nums[i] - 1; //if doesn't exists then process (prev element like for 101 it is 100)
        if (!s.count(tmp))
        {                         // if doesn't exists
            int curNum = nums[i]; // current number
            int curCnt = 1;       // current count of streak

            while (s.count(curNum + 1))
            {                // smallest number, like for 1 we check 2..3..4
                curNum += 1; //increase current number
                curCnt += 1; //and streak
            }
            cnt = max(cnt, curCnt); //it is max of current and longest
        }
    }
    return cnt;
}

int main()
{

    return 0;
}