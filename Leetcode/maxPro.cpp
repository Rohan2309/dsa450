/*
152. Maximum Product Subarray
Medium

8675

272

Add to List

Share
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro1 = INT_MIN; // from left to right
        int maxPro2 = INT_MIN; // from right to left
        int n = nums.size();
        
        if(n==1){ //base case
            return nums[0];
        }
        
        int prod = 1;
        //traversing from left to right
        //storing max value in maxPro1
        for(int i=0; i< n; i++){
            
            if(nums[i]==0){
                prod = 1;
            }else{
                prod*=nums[i];
                maxPro1 = max(maxPro1,prod);
            }
            
        }
        
        prod = 1;//resetting product
        
        //traversing from right to left
        //storing max value in maxPro2
        for(int i = n-1; i>0; i--){
            
            
            if(nums[i]==0){
                prod =1;
            }else{
                prod*=nums[i];
                maxPro2 = max(maxPro2,prod);
            }
        }
        int res = max(maxPro1, maxPro2); 
        //incase it is a negative value
        return max(res, 0);
    }
};

int main()
{
    
    return 0;
}