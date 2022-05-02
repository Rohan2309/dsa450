/*
496. Next Greater Element I
Easy

2176

140

Add to List

Share
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        vector<int>ans;
        stack<int>s;
        //a1 = 4 1 2
        //a2 = 1 3 4 2 
        int n=n1.size(), m=n2.size(), a;
        for(int i=0; i<n; ++i){//looping through array 1, for 1st loop val is 4
            a=-1;
            for(int j=m-1;n2[j]!=n1[i];--j){//loop from last ele of arr2, loop will go till prev of matching ele
            //like 2 in case
                if(n2[j]>n1[i]) a=n2[j];//if we find greater ele in right push
            }
            ans.emplace_back(a);
        }
        return ans;
    }
};
int main()
{

    return 0;
}