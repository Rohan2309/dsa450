/*
485. Max Consecutive Ones
Easy

2285

392

Add to List

Share
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count  = 0;//for a certain range
        int maxn = 0;//ans
        int n = nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]==1){
                count++;//counter increases
            }else{//when 0 occurs, counter reinitializes
                count=0;
            }
            maxn = max(maxn,count);//max till now
        }
        return maxn;
        
    }
};
int main()
{
    
    return 0;
}