/*
78. Subsets
Medium

6995

123

Add to List

Share
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &v)
{
    if (v.empty())
    {
        return {{}}; //empty set
    }
    vector<vector<int>> ans = {{}}; //initialized with empty set
    for (int x : v)
    {                       //iterating through given vector
        int n = ans.size(); //size will change everytime
        for (int i = 0; i < n; i++)
        { //iterating through current resultant vect
            //for each step, the prev elements(vectors) will be there
            //plus we will add elements
            vector<int> tmp = ans[i]; //temp vect
            tmp.push_back(x);
            ans.push_back(tmp);
        }
    }

    return ans;
}

int main()
{

    return 0;
}