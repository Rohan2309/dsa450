/*
1. Two Sum
Easy

26823

862

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



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp; //will have number and index
        for(int i=0; i<n; ++i){
            int x = target - nums[i];
            if(mp.find(x)!= mp.end()){
                //we found the number
                ans.emplace_back(mp[x]);//index of x
                ans.emplace_back(i);//current index
                return ans; //assuming we have 1 ans
            }
            else{
                mp[nums[i]]=i;//if not found, we store its index
            }
        }
        return ans;
    }
};


int main()
{
    
    return 0;
}