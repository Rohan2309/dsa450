/*
189. Rotate Array
Medium

6342

1060

Add to List

Share
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/



#include <bits/stdc++.h>
using namespace std;


void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k= k%n; //less than n rotations makes sense
        //after n rotations everything remains same
        int pos = n-k;
        //1 2 3 4 5 6 7 8
        reverse(nums.begin(), nums.begin()+pos); //reverseing first half
        
        //5 4 3 2 1 6 7 8
        reverse(nums.begin()+pos, nums.end()); //reversing 2nd half
        
        //5 4 3 2 1 8 7 6
        reverse(nums.begin(), nums.end()); //reversing whole array
        
        //6 7 8 1 2 3 4 5
        
    }


    

int main()
{

    return 0;
}