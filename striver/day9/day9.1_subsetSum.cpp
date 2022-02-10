/*
Subset Sums 
Basic Accuracy: 56.36% Submissions: 15678 Points: 1
Given a list arr of N integers, print sums of all subsets in it.

Note: Return all the element is increasing order.

Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
 
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(int idx, int sum, vector<int>&v, vector<int>&arr,int n){
        if(idx==n){//base case
            v.emplace_back(sum);
            return;
        }
        helper(idx+1,sum+arr[idx],v,arr,n);//picking up the element
        helper(idx+1,sum,v,arr,n);//not picking up the element
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>v;//will hold all the subset sums
        helper(0,0,v,arr,N);//at first sum will be 0 and idx will be at 0
        sort(v.begin(),v.end());//sorting in asc order
        return v;
    }
};



int main()
{
    
    return 0;
}