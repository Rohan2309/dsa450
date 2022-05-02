/*
46. Permutations
Medium

9119

173

Add to List

Share
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/

#include <bits/stdc++.h>
using namespace std;
/*
Reccursion approach

class Solution {

 private:   
    void recFun(vector<int>&ds, vector<int>&a, vector<vector<int>> &ans, int freq[]){
        if(ds.size()==a.size()){//case when internal vec has size of main vector
            ans.push_back(ds);
            return;
        }
        for(int i=0; i< a.size(); i++){//traversing the whole main vec
            if(!freq[i]){//if unmarked (0)
                ds.push_back(a[i]);//push
                freq[i]=1;//update frq
                recFun(ds,a,ans,freq);//call rec func
                freq[i] = 0;//unmark
                ds.pop_back();//pop
            }
        }
    }
 public:   
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>>ans;//final ans
        vector<int>ds;//internal vec
        int n = a.size();
        int freq[n];//frequency array
        for(int i=0; i<n; i++){//initialized with 0
            freq[i]=0;
        }
        recFun(ds, a, ans, freq);
        return ans;
    }
};

*/

//Backstracking approach (no extra space)
class Solution {

 private:   
    void helper(int idx, vector<int>&v, int n, vector<vector<int>> &ans){
        if(idx==n){//base case, when idx reaches last
            ans.emplace_back(v);
            return;
        }
        for(int i=idx; i< n; ++i){//traversing the whole main vec, from idx
            swap(v[idx],v[i]);//swapping pos
            helper(idx+1,v,n,ans);//rec func wher we incre idx
            swap(v[idx],v[i]);//re swapping (backstraking)
        }
    }
 public:   
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>>ans;//final ans
        int n = a.size();
        helper(0, a, n, ans);//at first index is at 0
        return ans;
    }
};
int main()
{
    
    return 0;
}