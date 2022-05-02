/*
39. Combination Sum
Medium

8985

207

Add to List

Share
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, int x, vector<int>& c, vector<int>&v,int n,vector<vector<int>>&ans){
        if(idx==n){//base (index reaches last and target becomes 0)
            if(x==0){
                ans.emplace_back(v);
            }
            return;
        }
        //picking up the ele
        if(c[idx]<=x){//we only pick if ele is lesser than target
            v.emplace_back(c[idx]);//push ele
            helper(idx,x-c[idx],c,v,n,ans);//new target
            //same idx cause we can again pick it up
            v.pop_back();//when above rec is executed, then remove , before nopn pick
        }
        //not picking up
        helper(idx+1,x,c,v,n,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int x) {
        int n = c.size();
        vector<int>v;
        vector<vector<int>>ans;
        helper(0,x,c,v,n,ans);//at first index will be at 0
        return ans;
    }
};
int main()
{
    
    return 0;
}