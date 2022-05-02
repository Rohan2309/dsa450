/*
239. Sliding Window Maximum
Hard

9134

319

Add to List

Share
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        deque<int>dq;//will have indexes in decreasing fashion
        for(int i=0; i<n;++i){
            //max window size of k
            if(!dq.empty() and dq.front()==i-k){//removing out of bound eles from deque
                dq.pop_front();
            }
            //removing all smaller elements from dq, which are smaller than nums[i]
            while(!dq.empty() and nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            //storing in decreasing fashion in dq, index, At back
            dq.push_back(i);
            if(i>=k-1){// when k is 3 k-1 = 2, so when index is 2 we take maximum
                ans.emplace_back(nums[dq.front()]);
            }
        }
    return ans;
    }
};
int main()
{

    return 0;
}