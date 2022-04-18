/*
2172. Maximum AND Sum of Array
User Accepted:377
User Tried:1219
Total Accepted:494
Total Submissions:2766
Difficulty:Hard
You are given an integer array nums of length n and an integer numSlots such that 2 * numSlots >= n. There are numSlots slots numbered from 1 to numSlots.

You have to place all n integers into the slots such that each slot contains at most two numbers. The AND sum of a given placement is the sum of the bitwise AND of every number with its respective slot number.

For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
Return the maximum possible AND sum of nums given numSlots slots.

 

Example 1:

Input: nums = [1,2,3,4,5,6], numSlots = 3
Output: 9
Explanation: One possible placement is [1, 4] into slot 1, [2, 6] into slot 2, and [3, 5] into slot 3. 
This gives the maximum AND sum of (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2) + (3 AND 3) + (5 AND 3) = 1 + 0 + 2 + 2 + 3 + 1 = 9.
Example 2:

Input: nums = [1,3,10,4,7,1], numSlots = 9
Output: 24
Explanation: One possible placement is [1, 1] into slot 1, [3] into slot 3, [4] into slot 4, [7] into slot 7, and [10] into slot 9.
This gives the maximum AND sum of (1 AND 1) + (1 AND 1) + (3 AND 3) + (4 AND 4) + (7 AND 7) + (10 AND 9) = 1 + 1 + 3 + 4 + 7 + 8 = 24.
Note that slots 2, 5, 6, and 8 are empty which is permitted.
 

Constraints:

n == nums.length
1 <= numSlots <= 9
1 <= n <= 2 * numSlots
1 <= nums[i] <= 15
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMax(int idx, vector<int>&slotW, vector<int>&nums, int numSlots, map<pair<int, vector<int>>,int>&dp){
        if(idx>=nums.size())return 0;//filled up all the digits
        int maxi = INT_MIN;
        if(dp.find({idx,slotW})!=dp.end())return dp[{idx,slotW}];
        //putting all arr[idx] into every slot from 1 to num slots
        for(int i=1; i<=numSlots; ++i){
            //we can put if it is not full yet 
            if(slotW[i]<2) {
                slotW[i]++;//weight of first slot will go up
                int ans = (nums[idx]&i)+ findMax(idx+1, slotW, nums, numSlots,dp);
                slotW[i]--;
                maxi=max(maxi,ans);
            }
        }
        return dp[{idx,slotW}]=maxi;
    }
    
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int>slots(numSlots+1,0);
        map<pair<int, vector<int>>,int>dp;
        return findMax(0,slots,nums,numSlots,dp);
    }
};
int main() {
	return 0;
}