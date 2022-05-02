/*
540. Single Element in a Sorted Array
Medium

4648

107

Add to List

Share
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //naive approach
    /*
    As every number in the array repeats twice and only one number occurs once, we can take advantage of the XOR(^) operator. These are two properties of the XOR operator which will be helpful.

If p is a number then,

p^p=0

p^0=p

If we find the XOR of every element of the array, we will get the answer.
    */
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int h=n-2;//2nd last idx, as edge case when single digit is at end then at last low will point end
        //binary search
        while(l<=h){
            int m =(l+h)>>1;// divided by 2
            //in order to check it's in the left half
            //odd idx ->2nd place, check left if 1st is there or not
            //even idx ->1st place
            if(nums[m]==nums[m^1]){//odd xor 1 definetyle even idx before that
                //if even we get next odd
                l=m+1;//if we are on the left half we shrink the left half
            }
            else{
                h=m-1;;//if we are on the right half we shrink the right half
            }
            
        }
        return nums[l];
    
    }
    
};
int main() {
	return 0;
}