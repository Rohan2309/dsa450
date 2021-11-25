/*
229. Majority Element II
Medium

3718

253

Add to List

Share
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //boyer moore voting algo
        //we can not have more than 2 majority elements
        vector<int> ans;
        int n = nums.size();
        int ele1 = -1;//initial values
        int ele2 = -1;
        int c1=0;
        int c2=0;
        int i;
        int k = n/3;
        for(i=0; i< n; i++){
            if(nums[i]==ele1){
                c1++;
            }
            else if(nums[i]==ele2){
                c2++;
            }
            else if(c1==0){
                ele1 = nums[i];
                c1++;
            }
            else if(c2==0){
                ele2= nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        //we got atleast 2 nums now we can check if they are greater than k or not
        c1=0;
        c2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==ele1){
                c1++;
            }
            else if(nums[i]==ele2){
                c2++;
            }
        }
        
        if(c1>k){
            ans.push_back(ele1);
        }
        if(c2>k){
            ans.push_back(ele2);
        }
        
        return ans;
    }
};

int main(){
    return 0;
}