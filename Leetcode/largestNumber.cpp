/*
179. Largest Number
Medium

3914

358

Add to List

Share
Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
Example 3:

Input: nums = [1]
Output: "1"
Example 4:

Input: nums = [10]
Output: "10"
*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
    
    static bool comp(string &s1, string &s2){
        return(s1+s2)>=(s2+s1); 
    }
    
public:
    
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        //checking all values are 0 or not
        int x =0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                x++; //total no of 0 eles in x
            }
        }
        
        if(x==n){ //if all eles are 0
            return "0";
        }
        
        vector<string> s(n,""); //string vector
        
        for(int i=0; i<n ;i++){
            s[i]= to_string(nums[i]); //taking all values as string
        }
        
        sort(s.begin(), s.end(), comp);
        
        string ans = "";
        
        for(int i=0; i<n; i++){
            ans+=(s[i]);
        }
        
        return ans;
        
    }
};
    

int main()
{

    return 0;
}