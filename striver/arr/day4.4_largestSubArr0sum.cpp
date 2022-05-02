/*
Largest subarray with 0 sum 
Easy Accuracy: 46.94% Submissions: 77817 Points: 2
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {
        
        int sum  = 0; //sum of ele trav so far
        int mx = 0; //length of l sub arr with sum = 0
        unordered_map<int,int> mp; //prefix sum of every element, idx
        for(int i =0 ; i<n ; ++i){
            sum+=A[i];
            if(sum==0){//subarray untill curr idx has sum 0
            mx = max(mx, i+1);//update max with the maximum value of (max, current_index+1)

            }
            else{//If sum is not equal to zero then we check hashmap if we’ve seen a subarray with this sum before
                if(mp.find(sum)!=mp.end()){//if HashMap contains sum
                    mx = max(mx, i - mp[sum]);//so we update our max 
        /*  
        if we observe that 2 elements have same prefix sum, 
        we can conclude that the 2nd part of this subarray sums to zero
        */
                }
                else{
                    mp[sum]=i;// Insert (sum, current_index) into hashmap to store prefix sum until current index
                }
            }

        }
        return mx;
    }
};


int main()
{
    
    return 0;
}