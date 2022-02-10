/*
40. Combination Sum II
Medium

4504

123

Add to List

Share
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx, int x, vector<int>& c, vector<int>&v,int n,vector<vector<int>>&ans){
        if(x==0){//base, target becomes 0
            ans.emplace_back(v);
            return;
        }
        //picking up the ele
        for(int i=idx; i<n; ++i){
            //when i=idx we can pick it as it is the first ele
            //when i>idx and it is same as prev ele then we skip
            if(i>idx and c[i]==c[i-1])continue;//skip duplicates
            if(c[i]>x)break;//if ele is greater than target there is no point picking up els in right as arr is sorted
            //if these passes
            v.emplace_back(c[i]);//pushingin ds
            helper(i+1,x-c[i],c,v,n,ans);//rec func, moving to next index and reducing target val
            v.pop_back();//clearing ds after rec is executed
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int x) {
        int n = c.size();
        sort(c.begin(), c.end());//as we are not gonna pick repeated eles
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