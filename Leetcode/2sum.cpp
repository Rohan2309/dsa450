/*
1. Two Sum
Easy

24109

800

Add to List

Share
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mp; //value and index
    int numberToFind;
    for (int i = 0; i < n; i++)
    {                                    //when i is 2
        numberToFind = target - nums[i]; //9-2 is 7
        if (mp.find(numberToFind) != mp.end())
        { //if the numberTo find exists in hashtable then it will never point to end of it.

            ans.push_back(mp[numberToFind]); //storing index of map value
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]] = i; //if not found in the hash then we store it with index
    }
    return ans;
}

int main()
{

    return 0;
}