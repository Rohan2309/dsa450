/*
287. Find the Duplicate Number
Medium

10035

1027

Add to List

Share
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1

Basic approach
sort the given array -> val of idx i will be same as val of idx i+1

Optimal soln -> hashing (freq array of similar size initialized with 0)
when already freq is already 1 , then that is the output

most optimal -> linkedlist cycle method
when array is 2 5 9 6 9 3 8 9 7 1
and idx are   0 1 2 3 4 5 6 7 8 9

fist we have 2 ast idx 0 -> we go to idx 2 and we find 9
we go to idsx 9 we find 1...then 5 ..3..6..8..7..

we use slow and fast pointer, slow 1 step and fast 2 steps
when slow and fast collides we stop.
fast ptr will be at 1st point 
then move bith pointers by 1, when they collide we get dup number
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //initializing at the beginning
       int slow = nums[0];
       int fast = nums[0];
       do{
           slow = nums[slow];//we move slow by 1
           fast = nums[nums[fast]];//fast by 2
       }while(slow!=fast);
       //slow will stay there
       //when the meet, re initialize fast at the beginning
        fast = nums[0];
    while(slow!=fast){
            slow = nums[slow];//we move slow by 1
            fast = nums[fast];//fast by 1
        }
        return slow;//either of slow or fast will be the answer
    }
};

int main(){
    return 0;
}