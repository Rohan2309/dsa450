/*
493. Reverse Pairs
Hard

2135

167

Add to List

Share
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int merge(vector<int>&nums, int low, int mid, int high){
        int cnt = 0;
        //start point of left half of the array is low
        int j = mid + 1; //start point of right half of the array
        
        //iterating throgh left half of the array
        for(int i=low; i<=mid; ++i){
            //moving the j pointer for every i
            //j<=high -> till right array is over
            //nums[i]>2LL*nums[j] , cond. is satisfied
            while(j<=high and nums[i]>2LL*nums[j]){
                j++;
            }
            //if any of these cond. is not satisfied we break out of the while loop
            
            cnt += (j-(mid+1)); //number of elements on the left of j that will contribute
        }
        
        //now performing merge func.
        vector<int> tmp;
        int left = low; //at first idx of left array
        int right = mid+1; //at first idx of right array
        
        while(left<=mid and right<=high){
            if(nums[left]<= nums[right]){//whichever element is small, we push to ds
                tmp.push_back(nums[left++]);//then incre ptr
            }
            else{ //if right is smaller than left
                tmp.push_back(nums[right++]);
            }
        }
        
        
        while(left<=mid){
            tmp.push_back(nums[left++]);//then incre ptr
        }
        
        while(right<=high){
            tmp.push_back(nums[right++]);
        }
        
        //copying tmp array to nums array
        for(int i=low; i<=high; ++i){
            nums[i]= tmp[i-low];
        }
        
        return cnt;
    }
    
    int mgSort(vector<int>&nums, int low, int high){
        if(low>=high){
            return 0;
        }
        int mid = (low+high)/2;
        //breaking into two halves
        int inv = mgSort(nums, low, mid); //left rec
        inv += mgSort(nums, mid+1, high); // right rec
        inv += merge(nums, low, mid, high); //joining them
        return inv;
        
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mgSort(nums, 0, n-1);
    }
};


int main()
{
    
    return 0;
}