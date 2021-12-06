/*
18. 4Sum
Medium

4912

592

Add to List

Share
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()==0){
            return ans;
        }
        int n = nums.size();

        sort(nums.begin(), nums.end());//cond. for binary search
        
        for(int i=0; i<n ; ++i){
            int target3 = target - nums[i];

            for(int j=i+1; j<n; ++j){
                int target2 = target3 - nums[j];

                //2 pointer , one at front and the other at back
                int front = j+1;
                int back = n-1;

//applying binary search now
                while(front<back){
                    int sum = nums[front] + nums[back];
                    if(sum<target2){
                        ++front;
                    }
                    else if(sum>target2){
                        --back;
                    }
                    else{
                        vector<int>res(4,0); //sz 4 , init 0
                        res[0]=nums[i];
                        res[1]=nums[j];
                        res[2]=nums[front];
                        res[3]=nums[back];
                        ans.emplace_back(res);

                        //we don't want duplicates
                        while(front<back and nums[front]==res[2]){
                            ++front;
                        }

                        while(front<back and nums[back]==res[3]){
                            --back;
                        }
                    }
                    while(j+1 < n and nums[j+1]==nums[j]){
                        ++j;
                    }

                }
                while(i+1 < n and nums[i+1]==nums[i]){
                    ++i;
                }
            }
            
    }
        return ans;
    }
};

int main()
{
    
    return 0;
}