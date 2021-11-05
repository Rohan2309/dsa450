/*
56. Merge Intervals
Medium

10133

443

Add to List

Share
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>>ans;
        int n = v.size();
        if(n==0){
            return ans;//return empty vect
        }
        sort(v.begin(),v.end());
        vector<int>temp = v[0]; //putting first vector into temp vector
        //this temp vect is used for comparison
        //iterating
        //temp is initially 1,3
        
        for(auto it: v){//let's compare v  when v is at 2,4 ...so 3 is bigger than 2 so we merge
            if(it[0]<=temp[1]){//when right of first vect(temp[1]) is bigger than left of 2nd vect(it[0]) then merging
                temp[1]= max(it[1],temp[1]);//max of right of first or the right of 2nd
                //as temp[0] (left side of temp) will be as it is
            }
            else{
                ans.push_back(temp);//if we can't merge push into ans
                temp=it;//re initialize temp
            }
        }
        //whatever data is left in temp put that in ds
        ans.push_back(temp);
        return ans;
    }
};

int main(){
    return 0;
}