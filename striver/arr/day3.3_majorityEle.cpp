/*
169. Majority Element
Easy

6983

296

Add to List

Share
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algo
        int cnt = 0;
        int ele = 0;
        
        for(int num : nums){
            if(cnt==0){ // when counter is 0
                ele = num; // that digit will be assumed as majority element
            }
            if(num == ele){ //if element is that num,  then incre counter
                cnt++;
            }
            else{//or if different element comes, decrease the counter
                cnt--;
            }
        }
        // at last the ele which is there, is the majority element
        return ele;
    }
};

int main(){
    return 0;
}