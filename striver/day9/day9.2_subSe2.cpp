/*
90. Subsets II
Medium

4332

139

Add to List

Share
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, vector<int>&v, vector<vector<int>>&ans, vector<int>&nums, int n){
        ans.emplace_back(v);//n complexity for null subset at first(deep copy)
        for(int i = idx; i<n; ++i){
            if(i!=idx and nums[i]==nums[i-1])continue;//skipping duplicates, though we can keep the 1st ele
            v.emplace_back(nums[i]);
            helper(i+1,v,ans,nums,n);//for next ele
            v.pop_back();//clearing v after every subset
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;//for a single subset
        vector<vector<int>>ans;//all subsets
        int n = nums.size();
        sort(nums.begin(), nums.end());//sorting so that we can skip duplicates
        helper(0,v,ans,nums,n);//ids will be at 0 
        return ans;
    }
};

int main()
{
    
    return 0;
}